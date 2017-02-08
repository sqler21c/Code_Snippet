package com.pantech.alarmwindowandlitview;

import java.io.File;

import android.os.Environment;
import android.os.StatFs;

/**
 * Created by user on 2017-02-06.
 */

public class MemoryStatus {

    static final int ERROR = -1;

   static public boolean externalMemoryAvailable(){
        return android.os.Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED);
    }

   static public long getAvailableInternalMemorySize() {
        File path = Environment.getDataDirectory();
        StatFs stat = new StatFs(path.getPath());
        //long blockSize = stat.getBlockSize();
        long blockSize = stat.getBlockSizeLong();
        // long availableBlocks = stat.getAvailableBlocks();
        long availableBlocks = stat.getAvailableBlocksLong();

        return availableBlocks * blockSize;
    }

   static public long getTotalInternalMemorySize() {
        File path = Environment.getDataDirectory();
        StatFs stat = new StatFs(path.getPath());
        //long blockSize = stat.getBlockSize();
        long blockSize = stat.getBlockSizeLong();
        //long totalBlocks = stat.getBlockCount();
        long totalBlocks = stat.getBlockCountLong();
        return totalBlocks * blockSize;
    }

   static public long getAvailableExternalMemorySize() {
        if(externalMemoryAvailable()) {
            File path = Environment.getExternalStorageDirectory();
            StatFs stat = new StatFs(path.getPath());
            //long blockSize = stat.getBlockSize();
            long blockSize = stat.getBlockSizeLong();
            //long availableBlocks = stat.getAvailableBlocks();
            long availableBlocks = stat.getAvailableBlocksLong();

            return availableBlocks * blockSize;
        } else {
            return ERROR;
        }
    }

   static public long getTotalExternalMemorySize() {
        if(externalMemoryAvailable()) {
            File path = Environment.getExternalStorageDirectory();
            StatFs stat = new StatFs(path.getPath());
            //long blockSize = stat.getBlockSize();
            long blockSize = stat.getBlockSizeLong();
            //long totalBlocks = stat.getBlockCount();
            long totalBlocks = stat.getBlockCountLong();

            return totalBlocks * blockSize;
        } else {
            return ERROR;
        }
    }

   static public String formatSize(long size) {
        String suffix = null;

        if (size >= 1024) {
            suffix = "KiB";
            size /= 1024;
            if (size >= 1024) {
                suffix = "MiB";
                size /= 1024;
                if (size >= 1024){
                    suffix = "GiB";
                    size /= 1024;
                }
            }
        }

        StringBuilder resultBuffer = new StringBuilder(Long.toString(size));

        int commaOffset = resultBuffer.length() - 3;
        while (commaOffset > 0) {
            resultBuffer.insert(commaOffset, ',');
            commaOffset -= 3;
        }

        if (suffix != null) resultBuffer.append(suffix);

        return resultBuffer.toString();
    }
}
