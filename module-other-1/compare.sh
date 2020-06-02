cd backup_output_files_run2
echo $PWD

folder="ls $1"
#echo $folder
rm compared.log
for i in ./*
  do
    echo $i
    cmd="diff 10/Output_1024x768_f32.y  $i/Output_1024x768_f32.y"
    $cmd &>> compared.log 
    cmd1="diff 10/Output_1024x768_f32.y  $i/Output1_1024x768_f32.y"
    cmd2="diff 10/Output_1024x768_f32.y  $i/Output2_1024x768_f32.y"
    cmd3="diff 10/Output_1024x768_f32.y  $i/Output3_1024x768_f32.y"
    cmd4="diff 10/Output_1024x768_f32.y  $i/Output4_1024x768_f32.y"
     
    $cmd1 &>> compared.log 
    $cmd2 &>> compared.log 
    $cmd3 &>> compared.log 
    $cmd4 &>> compared.log 
    #cmd5="diff ../Output_1024x768_f32.y $i/Output_1024x768_f32.y"
    #$cmd5 &>> compared.log
 done

