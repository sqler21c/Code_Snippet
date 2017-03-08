/*
		 *	Top acivity인지 판단
		 *	getRunningTasks 함수 더 이상 지원 하지 않음 아래 구문으로 대체 함
		 *
		 *	added date : 2016/7/27
		 *	by : SGK
		 *	Team : Quality 1 Team
         *
		 */
		final int PROCESS_STATE_TOP = 2;
		ActivityManager.RunningAppProcessInfo currentInfo = null;
		Field field = null;

		try{
			field = ActivityManager.RunningAppProcessInfo.class.getDeclaredField("processState");
		}catch(Exception e) {
			e.printStackTrace();
		}

		List<ActivityManager.RunningAppProcessInfo> applist = mActivityManager.getRunningAppProcesses();

		for(ActivityManager.RunningAppProcessInfo app : applist){

			if (app.importance == ActivityManager.RunningAppProcessInfo.IMPORTANCE_FOREGROUND
					&& app.importanceReasonCode == ActivityManager.RunningAppProcessInfo.REASON_UNKNOWN) {
				Integer state = null;
				try {
					state = field.getInt(app);
				} catch (Exception e) {
				}
				if (state != null && state == PROCESS_STATE_TOP) {
					currentInfo = app;
					break;
				}
			}

		}
