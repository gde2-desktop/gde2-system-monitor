#include <config.h>

#include <glib.h>

#include "procman.h"
#include "procman_gde2su.h"
#include "util.h"

gboolean (*gde2su_exec)(const char *commandline);


static void
load_gde2su(void)
{
    static gboolean init;

    if (init)
        return;

    init = TRUE;

    load_symbols("libgde2su.so.0",
             "gde2su_exec", &gde2su_exec,
             NULL);
}


gboolean
procman_gde2su_create_root_password_dialog(const char *command)
{
    return gde2su_exec(command);
}


gboolean
procman_has_gde2su(void)
{
    load_gde2su();
    return gde2su_exec != NULL;
}
