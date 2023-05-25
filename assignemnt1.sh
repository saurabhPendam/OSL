
#!/bin/bash
i=1
while((i==1))
do
 
echo -e "\n1.Create a Student Record"
echo "2.View Student Record "
echo "3.To add a record"
echo "4.To delete a record"
echo "5.To modify a record "
echo "6.Exit"
 
echo "Enter a choice : "
read choice
 
    case $choice in
    1)
        echo "Enter the name of the file : "
        read filename
        
        len=$(echo -n $filename | wc -m)
        if test $len -gt 0;
            then
                fname=$filename
                if test -f "$filename";
                    then 
                    echo -e "Student Record $filename already exists.\n"
                        echo -e "\n"
                else
                        touch $filename
                        echo -e "Student Record with name $filename was created successfully.\n"
                fi  
        else
            echo -e "File cannot be created\n"
            
        fi
        
    ;;
    
    2)
 
        if test -n "$fname";
        then 
            if test ! -s "$fname";
            then 
                echo -e "File is empty\n"
            else
                echo -e "The Student Record is as follows : \n"
                cat  $fname 
            fi
        
        else
            echo -e "File does not exist\n"
        fi
        
    ;;
    3)
 
        if test ! -z "$fname";
            then
                echo -e "Inserting a record into  Student database"
                echo -e "Enter the details of Student............."
 
                echo "Enter the name of the student : "
                read sname
                echo "Enter the roll no : "
                read rno
                echo "Enter division of the student :"
                read div
                echo -e "$sname \t\t $rno\t\t$div" >>$fname
        else
                echo -e "File does not exist\n"
        fi
        
    ;;      
                            
    4)  
        if test -n "$fname"
            then
                echo -e "Deleting a record from File"
                echo -e "Enter the name of person whose record is to be deleted : "
                read name
                echo -e "\n"
                del_record="$(grep "^$name\s" $fname)"
                if test $? -ne 0
                    then
                        echo -e "The name you entered does not exist in Student Record\n"
                else
                    grep -v "^$name\s" $fname | cat >>temp
                    mv temp $fname
                    echo -e "The record has been deleted successfully\n"
 
                fi
        else
            echo -e "File does not exist\n"
        fi
    ;;
    
    5)
        if test -n "$fname"
            then
                echo -e "Modifying a record from File"
                echo -e "Enter the name of person whose record is to be modified : "
                read name
                echo -e "\n"
                old_record="$(grep "^$name\s" $fname)"
                if test $? -ne 0
                    then
                        echo -e "The name you entered does not exist in Student Record\n"
                else
                    echo  "Enter the modified details below"
                    echo  "Enter the name of the student : "
                    read newname
                    echo "Enter the roll no : "
                    read newrno
                    echo "Enter division of the student :"
                    read newdiv
                new_record="$newname \t\t $newrno\t\t$newdiv"
                sed -i "s/$old_record/$new_record/g" $fname
                echo -e "Record Modified\n"
                fi
        else
            echo -e "File does not exist\n"
        fi
    ;;  
    
    6)
            echo "Sucessfully exited from Student Record......."
            i=-1
    ;;
    *)
        echo "Please Enter a Valid Option"
    ;;
    esac
done
    
    
