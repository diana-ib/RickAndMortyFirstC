# RickAndMortyFirstC
test 13:print_by_planet(option 5 in menu):Incorrect program output - Input - \  - Program output -./closedTestScript.sh: line 35: 1374786 Segmentation fault      (core dumped) ./ManageJerries 7 10 configuration_file_closed.txt &lt; $1 2> err.txt > out.txt BUG. \ --- Expected output (text)---  TRUE \Summary of tests -15 tests run/14 tests passed 


בפונקציות היצור , הטיפוס שמחזירה אותו הפונקציה הוא מצביע מסוג הסטרקט, ובתוך כל פונקצית יצור הייתי מקצה זכרון דינאמי בheap בביצוע פעולת malloc 
אחרי כל הקצאת זכרון בודקת אח הצלחתי או לא, אם לא הצלחתי משחררת מה שהקציתי לפני באותה פונקציה . 

בפונקציות ההריסה , בכל פונקציה משחררת לפי כמה פעמים עשיתי malloc מפנים לבחוץ 

בשאר הפונקציות הייתי בודקת בתחילת כל פונקציה שמקבלת כפרמטר מצביע למשהו אם המצביע המקבלת אותו הוא ריק או לא 
עשיתי פונקצית עזר בmain כדי שלא תהיה חשופה למשתמש , כל הסטרקטים והגדרת הפונקציות עשיתי בקובץ הh 
מימוש הפונקציות עשיתי בקובץ c 
חשבתי לשים גם את הסטרקטים בקובץ c אבל זה מודל רגיל ולא adt כמו שלמדנו בשיעור שעבר

