 // version.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        string output;
//      write(__VERSION__+"\n");
        output = read_file("/doc/help/version.txt");
        write(output);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : version
 
���ָ�����ʾ��ϷĿǰ���õ�MudOS�Լ�MudLIB�汾.
 
HELP
    );
    return 1;
}
   
