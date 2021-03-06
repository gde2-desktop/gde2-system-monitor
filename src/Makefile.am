## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-DPROCMAN_DATADIR=\""$(datadir)/procman/"\" \
	-DGDE2LOCALEDIR=\""$(datadir)/locale"\" \
	-DDATADIR=\""$(datadir)"\" \
	@PROCMAN_CFLAGS@ \
	@SYSTEMD_CFLAGS@

bin_PROGRAMS = gde2-system-monitor

gde2_system_monitor_cpp_files = \
	argv.cpp \
	procman.cpp \
	interface.cpp \
	callbacks.cpp \
	load-graph.cpp \
	proctable.cpp \
	prettytable.cpp \
	util.cpp \
	procactions.cpp \
	procdialogs.cpp \
	memmaps.cpp \
	openfiles.cpp \
	procproperties.cpp \
	smooth_refresh.cpp \
	disks.cpp \
	selinux.cpp \
	cgroups.cpp \
	procman_gde2su.cpp \
	procman_gksu.cpp \
	sysinfo.cpp \
	lsof.cpp \
	selection.cpp \
	settings-keys.cpp \
	iconthemewrapper.cpp

gde2_system_monitor_c_files = \
	e_date.c \
	gsm_color_button.c

gde2_system_monitor_h_files = \
	$(gde2_system_monitor_cpp_files:.cpp=.h) \
	$(gde2_system_monitor_c_files:.c=.h) \
	defaulttable.h

gde2_system_monitor_SOURCES = \
	$(gde2_system_monitor_h_files) \
	$(gde2_system_monitor_cpp_files) \
	$(gde2_system_monitor_c_files)

gde2_system_monitor_LDADD = @PROCMAN_LIBS@ @SYSTEMD_LIBS@ libbacon.la


noinst_LTLIBRARIES = libbacon.la
libbacon_la_SOURCES = \
	bacon-message-connection.c \
	bacon-message-connection.h


specdir = $(datadir)/procman


# GSettings schemas, enum files and conversion file
gsettings_ENUM_NAMESPACE = org.gde2.system-monitor
gsettings_ENUM_FILES = $(top_srcdir)/src/*.h
gsettingsschema_in_files = org.gde2.system-monitor.gschema.xml.in
gsettings_SCHEMAS = $(gsettingsschema_in_files:.xml.in=.xml)
@GSETTINGS_RULES@
@INTLTOOL_XML_NOMERGE_RULE@

convertdir = $(datadir)/Gde2Conf/gsettings
dist_convert_DATA = gde2-system-monitor.convert

dist_noinst_DATA = \
	$(gsettings_in_file)

CLEANFILES = \
	$(gsettings_SCHEMAS)

EXTRA_DIST = \
	$(gsettingsschema_in_files)

MAINTAINERCLEANFILES = $(gsettings_SCHEMAS:.xml=.valid)
