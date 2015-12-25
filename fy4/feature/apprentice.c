 // apprentice.c
#include <dbase.h> 
int is_apprentice_of(object ob)
{
    mapping family;
    
    if( !mapp(family = query("family")) ) return 0;
    
    return( family["master_id"] == (string)ob->query("id")
        && family["master_name"] == (string)ob->query("name") 
        && family["family_name"] == (string)ob->query("family/family_name")
        && ob->query("family/privs") == -1 );
} 
int is_couple_of(object ob)
{
    if((string)query("marry") == (string)ob->query("id") &&
       (string)query("id") == (string)ob->query("marry"))
        return 1;
    return 0;
} 
varargs void assign_title(string title, int nogen)
{
    mapping family;
    int gen;
    if( !mapp(family = query("family")) ) return; 
    family["title"]=title;
    if(!nogen)
    {
        gen=family["generation"];
        //self set rank_nogen can override assign_title's arg
        if(gen > 1 && query("rank_nogen")==0)
            title=sprintf("��%s��%s", chinese_number(gen), title);
    }
    set("title",family["family_name"]+" "+title);
    
} 
// This is used for NPC, or start a new family for a player.
void create_family(string family_name, int generation, string title)
{
    mapping family;
    
    family = allocate_mapping(6);
    
    family["family_name"] = family_name;
    family["generation"] = generation;
    // priv = -1 for ALL privileges.
    family["privs"] = -1;
    set("family", family);
    
    assign_title(title);
} 
//check if the player is a member of a certain organization
int is_member_of(object ob)
{
    mapping organization;
    
    if( !mapp(organization = query("organization")) ) return 0;
    
    return( organization["leader_id"] == (string)ob->query("id")
        && organization["leader_name"] == (string)ob->query("name") 
        && organization["org_name"] == (string)ob->query("organization/org_name")
        && ob->query("organization/privs") == -1 );
} 
//this will be used for NPC organization, or start a new Organization for a player
void create_organization(string org_name,int generation, string org_attribute )
{
    mapping organization;
    
    organization = allocate_mapping(4);
    
    organization["org_name"] = org_name;
    organization["generation"] = generation;
        organization["org_attribute"] = org_attribute;
    // priv = -1 for ALL privileges.
    organization["privs"] = -1;
    set("organization", organization);
}     
