#ifndef H_GDE2_SYSTEM_MONITOR_DISKS_1123719137
#define H_GDE2_SYSTEM_MONITOR_DISKS_1123719137

#include "procman.h"

GtkWidget *
create_disk_view(ProcData *procdata);

int
cb_update_disks(gpointer procdata);

#endif /* H_GDE2_SYSTEM_MONITOR_DISKLIST_1123719137 */
