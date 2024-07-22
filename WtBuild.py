import os  
import datetime  
import sys  
def Create(target_file):         
    filename, ext = os.path.splitext(target_file)  
    db_file_path = filename+'.db'
    file_path = target_file  
    
    try:  
        with open(db_file_path, 'r+') as f:  
            build_number = int(f.read().strip())  
            f.seek(0)
            if build_number == 255:  
                build_number = 0  
            else:  
                build_number += 1  
            f.write(str(build_number))  
    except FileNotFoundError:  
        with open(db_file_path, 'w') as f:  
            f.write('0')  
        build_number = 0  
    except Exception as e:  
        print("[WtBuild]Error reading or writing build number: %d" % (e))  
        return  
      
    now = datetime.datetime.now().strftime('%Y%m%d%H%M%S%f')  
  
  
    print("[WtBuild]Number: %d, Time: %s" % (build_number, now[:-3])) 
      
    try:  
        with open(file_path, 'w') as f:  
            f.write('#ifndef __WT_BUILD_H__\n')  
            f.write('#define __WT_BUILD_H__\n')  
            f.write('#define WT_BUILD_NUMBER %d\n' % (build_number))               
            f.write('#define WT_BUILD_YEAR_4 %s\n' % (now[0]))
            f.write('#define WT_BUILD_YEAR_3 %s\n' % (now[1]))
            f.write('#define WT_BUILD_YEAR_2 %s\n' % (now[2]))  
            f.write('#define WT_BUILD_YEAR_1 %s\n' % (now[3]))  
            f.write('#define WT_BUILD_MONTH_2 %s\n' % (now[4]))
            f.write('#define WT_BUILD_MONTH_1 %s\n' % (now[5]))
            f.write('#define WT_BUILD_DAY_2 %s\n' % (now[6]))
            f.write('#define WT_BUILD_DAY_1 %s\n' % (now[7]))  
            f.write('#define WT_BUILD_HOUR_2 %s\n' % (now[8]))
            f.write('#define WT_BUILD_HOUR_1 %s\n' % (now[9]))  
            f.write('#define WT_BUILD_MINUTE_2 %s\n' % (now[10]))
            f.write('#define WT_BUILD_MINUTE_1 %s\n' % (now[11]))              
            f.write('#define WT_BUILD_SECOND_2 %s\n' % (now[12]))  
            f.write('#define WT_BUILD_SECOND_1 %s\n' % (now[13])) 
            f.write('#define WT_BUILD_MILLISECOND_3 %s\n' % (now[14]))
            f.write('#define WT_BUILD_MILLISECOND_2 %s\n' % (now[15]))
            f.write('#define WT_BUILD_MILLISECOND_1 %s\n' % (now[16])) 
            f.write('#endif\n')  
    except Exception as e:  
        print("[WtBuild]Error writing to file %s: %d" % (file_path, e))  

if __name__ == '__main__':  
    if len(sys.argv)>1:
        Create(sys.argv[1])
    else:  
        print("[WtBuild]Usage: python WtBuild.py file_path")
