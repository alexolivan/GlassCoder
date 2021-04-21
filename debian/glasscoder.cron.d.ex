#
# Regular cron jobs for the glasscoder package
#
0 4	* * *	root	[ -x /usr/bin/glasscoder_maintenance ] && /usr/bin/glasscoder_maintenance
