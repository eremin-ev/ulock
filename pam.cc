/*
 * This source code is licensed under the GNU General Public License,
 * Version 2.  See the file COPYING for more details.
 */

#include <security/pam_appl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int conv_cb(int num_msg, const struct pam_message **msg,
		   struct pam_response **resp, void *user_data_ptr)
{
	const char *passwd = (const char *)user_data_ptr;

	printf("%s num_msg: %i\n", __func__, num_msg);

	/* pam_conv */
	if (num_msg == 1) {
		*resp = (struct pam_response *)malloc(1 * sizeof(struct pam_response));
		(*resp)->resp_retcode = 0;
		(*resp)->resp = strdup(passwd);
		printf("%s %s <- '%s'\n", __func__, (*msg)->msg, (*resp)->resp);
	}

	return PAM_SUCCESS;
}

/*
 * Return true (1) if authenticated successfully
 */
int do_auth(const char *user, const char *passwd)
{
	struct pam_conv pam_conv = { conv_cb, (void *)passwd };
	pam_handle_t *pamh;

	printf("%s: '%s' '%s'\n", __func__, user, passwd);

	int res = pam_start("devicelock", user, &pam_conv, &pamh);

	if (res == PAM_SUCCESS) {
		res = pam_authenticate(pamh, 0);
	}

	if (res == PAM_SUCCESS) {
		res = pam_acct_mgmt(pamh, 0);
	}

	if (res == PAM_SUCCESS) {
		fprintf(stdout, "Authenticated.\n");
	} else {
		fprintf(stdout, "Not Authenticated.\n");
	}

	pam_end(pamh, res);

	return res == PAM_SUCCESS ? 1 : 0;
}
