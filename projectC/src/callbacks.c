#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include "enregistrement.h"
#include "client.h"
#include "employe.h"
#include "plante.h"
#include "annee.h"

int x;
int y;


void
on_connect_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *login, *pass;
	GtkWidget *home, *admin, *employee;
	char input1[100], input2[100];

	home=lookup_widget(objet,"home");
	admin=lookup_widget(objet,"admin");
	employee=lookup_widget(objet,"employee");

	login=lookup_widget(objet,"entry_login");
	pass=lookup_widget(objet,"entry_pass");
	strcpy(input1,gtk_entry_get_text(GTK_ENTRY(login)));
	strcpy(input2,gtk_entry_get_text(GTK_ENTRY(pass)));
	if(strcmp(input1,"admin")==0 && strcmp(input2,"admin")==0)
	{
		gtk_widget_destroy(home);
		admin=create_admin();
		gtk_widget_show(admin);
	}
	else
	{
		if((strcmp(input1,"user1")==0 && strcmp(input2,"azerty")==0) || (strcmp(input1,"user2")==0 && strcmp(input2,"123456789")==0) || (strcmp(input1,"user3")==0 && strcmp(input2,"00000000")==0))
		{
			gtk_widget_destroy(home);
			employee=create_employee();
			gtk_widget_show(employee);
		}
	}
}


void
on_decon_emp_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *home, *employee;

	home=lookup_widget(objet,"home");
	employee=lookup_widget(objet,"employee");

	gtk_widget_destroy(employee);
	home=create_home();
	gtk_widget_show(home);
}


void
on_plant_emp_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestiondeplantation, *employee;
	gestiondeplantation=lookup_widget(objet_graphique,"gestiondeplantation");
	employee=lookup_widget(objet_graphique,"employee");
	gtk_widget_destroy(employee);
	gestiondeplantation = create_gestiondeplantation();
	gtk_widget_show(gestiondeplantation);
}


void
on_troup_emp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_equip_emp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_client_emp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion_des_clients, *employee;
	gestion_des_clients=lookup_widget(objet,"Gestion_des_clients");
	employee=lookup_widget(objet,"employee");
	gtk_widget_destroy(employee);
	gestion_des_clients = create_Gestion_des_clients();
	gtk_widget_show(gestion_des_clients);
}


void
on_capt_emp_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *espace_capteur, *employee;
	espace_capteur=lookup_widget(objet,"espace_capteur");
	employee=lookup_widget(objet,"employee");
	gtk_widget_destroy(employee);
	espace_capteur = create_espace_capteur();
	gtk_widget_show(espace_capteur);
}


void
on_ouvr_emp_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_ouvr_admin_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_troup_admin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

}

void
on_gest_admin_emp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_des_employes, *admin;
	Gestion_des_employes=lookup_widget(objet,"Gestion_des_employes");
	admin=lookup_widget(objet,"admin");
	gtk_widget_destroy(admin);
	Gestion_des_employes = create_Gestion_des_employes();
	gtk_widget_show(Gestion_des_employes);
}

void
on_defect_admin_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *marque_def;
	GtkWidget *label;
	FILE *f;
	char marque[30];
	char marqueMax[30];
	int max=0;
	int nbr,i,j,cp;
	char tab[100][30];
	marque_def=lookup_widget(objet,"marque_def");
	marque_def = create_marque_def();
	label=lookup_widget(marque_def,"label_marque");
	strcpy(marqueMax,"N/A");
	f=fopen("defect.txt","a+");
	if(f!=NULL)
	{
	i=0;
	while(fscanf(f,"%s\n",marque)!=EOF)
	{
		strcpy(tab[i],marque);
		i=i+1;
	}
	for(j=0;j<i;j++)
	{
		nbr=0;
		for(cp=0;cp<i;cp++)
		{
			if(strcmp(tab[j],tab[cp])==0)
			{
				nbr=nbr+1;
			}
		}
		if(nbr>max)
		{
			max=nbr;
			strcpy(marqueMax,tab[j]);
		}
	}
	}
	fclose(f);
	gtk_label_set_text(GTK_LABEL(label),marqueMax);
	gtk_widget_show(marque_def);
}


void
on_absent_admin_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_seche_admin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion_annee_la_plus_seche, *admin;
	gestion_annee_la_plus_seche=lookup_widget(objet,"gestion_annee_la_plus_seche");
	admin=lookup_widget(objet,"admin");
	gtk_widget_destroy(admin);
	gestion_annee_la_plus_seche = create_gestion_annee_la_plus_seche();
	gtk_widget_show(gestion_annee_la_plus_seche);
}


void
on_decon_admin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *home, *admin;

	home=lookup_widget(objet,"home");
	admin=lookup_widget(objet,"admin");

	gtk_widget_destroy(admin);
	home=create_home();
	gtk_widget_show(home);
}

///////////////////////////////////////////////////////////////////////////////

void
on_treeview_capt_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* matricule;
	gchar* marque;
	gchar* type;
	gchar* etat_def;
	gint* val_min;
	gint* val_max;
	capteur capt;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &matricule, 1, &marque, 2, &type, 3, &etat_def, 4, &val_min, 5, &val_max, -1);
strcpy(capt.matricule,matricule);
strcpy(capt.marque,marque);
strcpy(capt.type,type);
strcpy(capt.etat_def,etat_def);
capt.val_min=val_min;
capt.val_max=val_max;
afficher_capteurs(treeview);
}
}


void
on_ajouter_capt_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_capteur;
	GtkWidget *gestion_capteur;
	gestion_capteur=lookup_widget(objet,"gestion_capteur");
	gtk_widget_destroy(gestion_capteur);
	ajouter_capteur = create_ajouter_capteur();
	gtk_widget_show(ajouter_capteur);
}


void
on_modifier_capt_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion_capteur;
	GtkWidget *modifier_capteur;
	GtkWidget *combo;
	FILE *f;
	char mat[30];
	gestion_capteur=lookup_widget(objet,"gestion_capteur");
	gtk_widget_destroy(gestion_capteur);
	modifier_capteur = create_modifier_capteur();
	combo=lookup_widget(modifier_capteur,"cb_mat_modif");
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*d %*d\n",mat)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),mat);
	}
	fclose(f);
	gtk_widget_show(modifier_capteur);
}


void
on_supprimer_capt_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion_capteur;
	GtkWidget *supprimer_capteur;
	GtkWidget *combo;
	FILE *f;
	char mat[30];
	gestion_capteur=lookup_widget(objet,"gestion_capteur");
	gtk_widget_destroy(gestion_capteur);
	supprimer_capteur = create_supprimer_capteur();
	combo=lookup_widget(supprimer_capteur,"combobox_supp");
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*d %*d\n",mat)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),mat);
	}
	fclose(f);
	gtk_widget_show(supprimer_capteur);
}


void
on_gestion_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_capteur;
GtkWidget *gestion_capteur;
GtkWidget *treeview_capt;
espace_capteur=lookup_widget(objet,"espace_capteur");

gtk_widget_destroy(gestion_capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}


void
on_enreg_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_capteur;
GtkWidget *enregistrement;
GtkWidget *treeview_enreg;
espace_capteur=lookup_widget(objet,"espace_capteur");

gtk_widget_destroy(enregistrement);
enregistrement=lookup_widget(objet,"enregistrement");
enregistrement=create_enregistrement();

gtk_widget_show(enregistrement);

treeview_enreg=lookup_widget(enregistrement,"treeview_enreg");

afficher_enregistrement(treeview_enreg);
}

void
on_rb_ajout1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_rb_ajout2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_ajout_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	capteur capt;
	char typeS[30]="Temperature";
	GtkWidget *input,*mat;

input= lookup_widget(objet,"entry_marque");

mat= lookup_widget(objet,"entry_mat");
strcpy(capt.marque,gtk_entry_get_text(GTK_ENTRY(input)));
if (x==1) 
{strcpy(typeS,"Temperature");}
else 
{if (x==2) 
{strcpy(typeS,"Humidite");}}
strcpy(capt.matricule,gtk_entry_get_text(GTK_ENTRY(mat)));
strcpy(capt.etat_def,"N/A");
strcpy(capt.type,typeS);
ajouter_capteur(capt);
}


void
on_retour_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
GtkWidget *ajouter_capteur;
GtkWidget *gestion_capteur;
GtkWidget *treeview_capt;
ajouter_capteur=lookup_widget(objet,"ajouter_capteur");

gtk_widget_destroy(ajouter_capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}


void
on_rb_modif1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_rb_modif2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_modif_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	capteur capt;
	char typeS[30]="Temperature";
GtkWidget *input,*type,*mat;
mat= lookup_widget(objet,"cb_mat_modif");
input= lookup_widget(objet,"entry_marque_modif");

strcpy(capt.matricule,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mat)));
strcpy(capt.marque,gtk_entry_get_text(GTK_ENTRY(input)));
if (y==1) 
{strcpy(typeS,"Temperature");}
else 
{if (y==2) 
{strcpy(typeS,"Humidite");}}

strcpy(capt.type,typeS);

modifier_capteur(capt);
}


void
on_retour_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		
GtkWidget *modifier_capteur;
GtkWidget *gestion_capteur;
GtkWidget *treeview_capt;
modifier_capteur=lookup_widget(objet,"modifier_capteur");

gtk_widget_destroy(modifier_capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}



void
on_supprim_ok_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur capt;
GtkWidget *input;
input= lookup_widget(objet,"combobox_supp");
strcpy(capt.matricule,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
supprimer_capteur(capt);
}


void
on_retour_supp_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer_capteur;
GtkWidget *gestion_capteur;
GtkWidget *treeview_capt;
supprimer_capteur=lookup_widget(objet,"supprimer_capteur");

gtk_widget_destroy(supprimer_capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}





void
on_treeview_enreg_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* num;
	date* date_enr;
	horaire* horaire_enr;
	gfloat *valeur;
	enregistrement enreg;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &num, 1, &date_enr, 2, &horaire_enr, 3, &valeur  -1);

afficher_enregistrement(treeview);
}
}


void
on_ajout_enreg_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_enregistrement, *enregistrement;
	GtkWidget *combo;
	FILE *f;
	char mat[30];
	enregistrement=lookup_widget(objet,"enregistrement");
	gtk_widget_destroy(enregistrement);
	ajouter_enregistrement = create_ajouter_enregistrement();
	combo=lookup_widget(ajouter_enregistrement,"cb_enreg");
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*d %*d\n",mat)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),mat);
	}
	fclose(f);
	gtk_widget_show(ajouter_enregistrement);
}


void
on_enreg_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	enregistrement enreg;

	GtkWidget *mat, *jour, *mois, *annee, *heure, *minute, *val;
	mat=lookup_widget(objet,"cb_enreg");
	jour=lookup_widget(objet,"spinbutton_jour");
	mois=lookup_widget(objet,"spinbutton_mois");
	annee=lookup_widget(objet,"spinbutton_annee");
	heure=lookup_widget(objet,"spinbutton_heure");
	minute=lookup_widget(objet,"spinbutton_minute");
	val=lookup_widget(objet,"entry_val");
	
	strcpy(enreg.matricule,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mat)));
enreg.dateE.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
enreg.dateE.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
enreg.dateE.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
enreg.horaireE.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
enreg.horaireE.minute=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(minute));
enreg.valeur=atof(gtk_entry_get_text(GTK_ENTRY(val)));

ajouter_enregistrement(enreg);
}


void
on_retour_enreg_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_enregistrement;
GtkWidget *enregistrement;
GtkWidget *treeview_enreg;
ajouter_enregistrement=lookup_widget(objet,"ajouter_enregistrement");

gtk_widget_destroy(ajouter_enregistrement);
enregistrement=lookup_widget(objet,"enregistrement");
enregistrement=create_enregistrement();

gtk_widget_show(enregistrement);

treeview_enreg=lookup_widget(enregistrement,"treeview_enreg");

afficher_enregistrement(treeview_enreg);
}


void
on_alarm_admin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
		
GtkWidget *admin;
GtkWidget *alarmante;
GtkWidget *treeview_alarm;
admin=lookup_widget(objet,"admin");

gtk_widget_destroy(alarmante);
alarmante=lookup_widget(objet,"alarmante");
alarmante=create_alarmante();

gtk_widget_show(alarmante);

treeview_alarm=lookup_widget(alarmante,"treeview_alarm");

afficher_alarmantes(treeview_alarm);
}


void
on_treeview_alarm_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* num;
	gfloat *valeur;
	enregistrement enreg;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &num, 1, &valeur  -1);

afficher_alarmantes(treeview);
}
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestion_des_clients;
GtkWidget *ajouter_clients;

ajouter_clients=create_ajouter_clients();
gtk_widget_show(ajouter_clients);
Gestion_des_clients=lookup_widget(objet_graphique,"Gestion_des_clients");
gtk_widget_hide(Gestion_des_clients);

}


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_clients;
GtkWidget *modifier_clients;

modifier_clients=create_modifier_clients();
gtk_widget_show(modifier_clients);
Gestion_des_clients=lookup_widget(objet_graphique,"Gestion_des_clients");
gtk_widget_hide(Gestion_des_clients);
}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_clients;
GtkWidget *supprimer_clients;

supprimer_clients=create_supprimer_clients();
gtk_widget_show(supprimer_clients);
Gestion_des_clients=lookup_widget(objet_graphique,"Gestion_des_clients");
gtk_widget_hide(Gestion_des_clients);
}


void
on_retour_client_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestion_des_clients;
GtkWidget *employee;

employee=create_employee();
gtk_widget_show(employee);
Gestion_des_clients=lookup_widget(objet_graphique,"Gestion_des_clients");
gtk_widget_hide(Gestion_des_clients);
}


void
on_button14_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

char cin[20];
GtkWidget *input18;

input18=lookup_widget(objet_graphique,"entry20");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input18)));
 
rechercher(cin);

gtk_entry_set_text(GTK_ENTRY(input18),"");
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview1");
afficher_client_rechercher(treeview1);

}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview1");
afficher_client(treeview1);
}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestion_des_clients;
GtkWidget *ajouter_clients;

Gestion_des_clients=create_Gestion_des_clients();
gtk_widget_show(Gestion_des_clients);
ajouter_clients=lookup_widget(objet_graphique,"ajouter_clients");
gtk_widget_hide(ajouter_clients);
}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

client a;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input8;
GtkWidget*Age;
GtkWidget*sortie21;

GtkWidget *ajouter_clients;

input1=lookup_widget(objet_graphique,"entry3");
input2=lookup_widget(objet_graphique,"entry4");
input3=lookup_widget(objet_graphique,"entry7");
input4=lookup_widget(objet_graphique,"entry5");
input5=lookup_widget(objet_graphique,"entry6");
input6=lookup_widget(objet_graphique,"entry8");
input8=lookup_widget(objet_graphique,"combobox1");
Age=lookup_widget(objet_graphique,"spinbutton1");

sortie21=lookup_widget(objet_graphique,"label35");

strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(a.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.telephone,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));
a.Age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Age));


ajouter_client(a);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie21,GTK_STATE_NORMAL,&color);

gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_label_set_text(GTK_LABEL(sortie21),"ajout réussi");

}


void
on_retour_capt_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *espace_capteur;
GtkWidget *employee;

employee=create_employee();
gtk_widget_show(employee);
espace_capteur=lookup_widget(objet_graphique,"espace_capteur");
gtk_widget_hide(espace_capteur);
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

client c;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6 , *input8;
GtkWidget*Age;
GtkWidget *sortie;
GtkWidget *modifier_clients;
GtkWidget*sortie22;

modifier_clients=lookup_widget(objet_graphique,"modifier_clients");
input1=lookup_widget(objet_graphique,"entry9");
input2=lookup_widget(objet_graphique,"entry10");
input3=lookup_widget(objet_graphique,"entry12");
input4=lookup_widget(objet_graphique,"entry14");
input5=lookup_widget(objet_graphique,"entry13");
input6=lookup_widget(objet_graphique,"entry11");
input8=lookup_widget(objet_graphique,"combobox2");
Age=lookup_widget(objet_graphique,"spinbutton2");
sortie22=lookup_widget(objet_graphique,"label65");

strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input6)));
c.Age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Age));
strcpy(c.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));


modifier_client(c);

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie22,GTK_STATE_NORMAL,&color);

gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_label_set_text(GTK_LABEL(sortie22),"modification réussi");
}


void
on_button8_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestion_des_clients;
GtkWidget *modifier_clients;

Gestion_des_clients=create_Gestion_des_clients();
gtk_widget_show(Gestion_des_clients);
modifier_clients=lookup_widget(objet_graphique,"modifier_clients");
gtk_widget_hide(modifier_clients);
}


void
on_button9_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget*sortie23;
char cin[40];
input1=lookup_widget(objet_graphique,"entry21");
sortie23=lookup_widget(objet_graphique,"label70");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
  
supprimer(cin);
gtk_entry_set_text(GTK_ENTRY(input1), "");
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie23,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie23),"suppression réussi");
}


void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_clients;
GtkWidget *supprimer_clients;

Gestion_des_clients=create_Gestion_des_clients();
gtk_widget_show(Gestion_des_clients);
supprimer_clients=lookup_widget(objet_graphique,"supprimer_clients");
gtk_widget_hide(supprimer_clients);
}


void
on_treeview_emp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* adresse;
	gchar* email;
	gchar* telephone;
	gint* Age;
	gchar* Sexe;
	employe a;
	

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &nom,1,&prenom,2,&cin,3,&adresse,4,&email,5,&telephone,6,&Age,7,&Sexe -1);
	strcpy(a.nom,nom);
	strcpy(a.prenom,prenom);
	strcpy(a.cin,cin);
	strcpy(a.adresse,adresse);
	strcpy(a.email,email);
	strcpy(a.telephone,telephone);
	a.Age=*Age;
	strcpy(a.Sexe,Sexe);
	
	afficher_employe(treeview);
	}
}


void
on_rech_admin_emp_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

char cin[20];
GtkWidget *input18;

input18=lookup_widget(objet_graphique,"entry_cin");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input18)));
 
rechercher_employe(cin);

gtk_entry_set_text(GTK_ENTRY(input18),"");
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview_emp");
afficher_employe_rechercher(treeview1);

}


void
on_affich_admin_emp_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview_emp");
afficher_employe(treeview1);
}


void
on_ajout_admin_emp_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestion_des_employes;
GtkWidget *ajouter_employes;

ajouter_employes=create_ajouter_employes();
gtk_widget_show(ajouter_employes);
Gestion_des_employes=lookup_widget(objet_graphique,"Gestion_des_employes");
gtk_widget_hide(Gestion_des_employes);
}


void
on_modif_admin_emp_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestion_des_employes;
GtkWidget *modifier_employes;

modifier_employes=create_modifier_employes();
gtk_widget_show(modifier_employes);
Gestion_des_employes=lookup_widget(objet_graphique,"Gestion_des_employes");
gtk_widget_hide(Gestion_des_employes);
}


void
on_supp_admin_emp_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_employes;
GtkWidget *supprimer_employes;

supprimer_employes=create_supprimer_employes();
gtk_widget_show(supprimer_employes);
Gestion_des_employes=lookup_widget(objet_graphique,"Gestion_des_employes");
gtk_widget_hide(Gestion_des_employes);
}


void
on_ajout_ok_emp_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
employe a;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input8;
GtkWidget*Age;
GtkWidget*sortie21;

GtkWidget *ajouter_employes;

input1=lookup_widget(objet_graphique,"nom_emp");
input2=lookup_widget(objet_graphique,"prenom_emp");
input3=lookup_widget(objet_graphique,"cin_emp");
input4=lookup_widget(objet_graphique,"adr_emp");
input5=lookup_widget(objet_graphique,"email_emp");
input6=lookup_widget(objet_graphique,"tel_emp");
input8=lookup_widget(objet_graphique,"cb_sexe_emp");

Age=lookup_widget(objet_graphique,"sb_age_emp");
sortie21=lookup_widget(objet_graphique,"label35");

strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(a.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.telephone,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));
a.Age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Age));



ajouter_employe(a);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie21,GTK_STATE_NORMAL,&color);

gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_label_set_text(GTK_LABEL(sortie21),"ajout réussi");

}


void
on_annuler_ajout_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_employes;
GtkWidget *ajouter_employes;

Gestion_des_employes=create_Gestion_des_employes();
gtk_widget_show(Gestion_des_employes);
ajouter_employes=lookup_widget(objet_graphique,"ajouter_employes");
gtk_widget_hide(ajouter_employes);
}


void
on_supp_ok_emp_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget*sortie23;
char cin[50];
input1=lookup_widget(objet_graphique,"entry215");
sortie23=lookup_widget(objet_graphique,"label150");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
  
supprimer_employe(cin);
gtk_entry_set_text(GTK_ENTRY(input1), "");
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie23,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie23),"suppression réussi");
}


void
on_annuler_supp_emp_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_employes;
GtkWidget *supprimer_employes;

Gestion_des_employes=create_Gestion_des_employes();
gtk_widget_show(Gestion_des_employes);
supprimer_employes=lookup_widget(objet_graphique,"supprimer_employes");
gtk_widget_hide(supprimer_employes);
}


void
on_modif_emp_ok_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
employe c;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6 , *input8;
GtkWidget*Age;
GtkWidget *sortie;
GtkWidget *modifier_employes;
GtkWidget*sortie22;

modifier_employes=lookup_widget(objet_graphique,"modifier_employes");
input1=lookup_widget(objet_graphique,"nom_modif_emp");
input2=lookup_widget(objet_graphique,"prenom_modif_emp");
input3=lookup_widget(objet_graphique,"adr_modif_emp");
input4=lookup_widget(objet_graphique,"tel_modif_emp");
input5=lookup_widget(objet_graphique,"email_modif_emp");
input6=lookup_widget(objet_graphique,"cin_modif_emp");
input8=lookup_widget(objet_graphique,"cb_sexe_modif_emp");
Age=lookup_widget(objet_graphique,"sb_age_modif_emp");
sortie22=lookup_widget(objet_graphique,"label88");

strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input6)));
c.Age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Age));
strcpy(c.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));



modifier_employe(c);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie22,GTK_STATE_NORMAL,&color);

gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_label_set_text(GTK_LABEL(sortie22),"modification réussi");
}


void
on_annuler_modif_emp_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_employes;
GtkWidget *modifier_employes;

Gestion_des_employes=create_Gestion_des_employes();
gtk_widget_show(Gestion_des_employes);
modifier_employes=lookup_widget(objet_graphique,"modifier_employes");
gtk_widget_hide(modifier_employes);
}


void
on_retour_kkkk_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *admin,*Gestion_des_employes;
	Gestion_des_employes=lookup_widget(objet_graphique,"Gestion_des_employes");
	gtk_widget_hide(Gestion_des_employes);
	admin=create_admin();
	gtk_widget_show(admin);
}
////////////////////////////////////////////////////////////////////////////////
void
on_retour_annee_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *admin,*Gestion_des_employes;
	Gestion_des_employes=lookup_widget(objet_graphique,"gestion_annee_la_plus_seche");
	gtk_widget_hide(Gestion_des_employes);
	admin=create_admin();
	gtk_widget_show(admin);
}
/////////////////////////////////////////////////////////////////////////////////

void
on_treeview_plant_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* nom;
	gchar* id;
	gchar* type;
	gchar* saison;
	gint* jour;
	gint* mois;
	gint* annee;
	gint* nombre;
	plante t;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &nom,1,&id,2,&type,3,&saison,4,&jour,5,&mois ,6,&annee ,7,&nombre,-1);
	strcpy(t.nom,nom);
	strcpy(t.id,id);
	strcpy(t.type,type);
	strcpy(t.saison,saison);
	t.d.jour=*jour;
	t.d.mois=*mois;
	t.d.annee=*annee;
	t.nombre=*nombre;
	afficher_plante(treeview);
	}
}


void
on_supprimer_plant_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondeplantation;
GtkWidget *Supprimer_plante;

Supprimer_plante=create_Supprimer_plante();
gtk_widget_show(Supprimer_plante);
Gestiondeplantation=lookup_widget(objet_graphique,"gestiondeplantation");
gtk_widget_hide(Gestiondeplantation);
}


void
on_modifier_plant_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondeplantation;
GtkWidget *Modifier_plante;
GtkWidget *treeview1;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
	gchar* nom;
	gchar* id;
	gchar* type;
	gchar* saison;
	gint* jour;
	gint* mois;
	gint* annee;
	gint* nombre;
	plante t;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*input8;
Gestiondeplantation=lookup_widget(objet_graphique,"gestiondeplantation");
treeview1=lookup_widget(Gestiondeplantation,"treeview_plant");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1));
if(gtk_tree_selection_get_selected(selection,&model,&iter)){
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &nom,1,&id,2,&type,3,&saison,4,&jour,5,&mois ,6,&annee ,7,&nombre,-1);
	strcpy(t.nom,nom);
	strcpy(t.id,id);
	strcpy(t.type,type);
	strcpy(t.saison,saison);
	/*t.d.jour=*jour;
	t.d.mois=*mois;
	t.d.annee=*annee;
	t.nombre=*nombre;*/
	
}
gtk_widget_hide(Gestiondeplantation);
Modifier_plante=create_Modifier_plante();
gtk_widget_show(Modifier_plante);
input1=lookup_widget(Modifier_plante,"nom_modif_plant");
input2=lookup_widget(Modifier_plante,"id_modif_plant");
input3=lookup_widget(Modifier_plante,"type_modif_plant");
input4=lookup_widget(Modifier_plante,"cb_saison_modif_plant");
input5=lookup_widget(Modifier_plante,"sb_jour_modif_plant");
input6=lookup_widget(Modifier_plante,"sb_mois_modif_plant");
input7=lookup_widget(Modifier_plante,"sb_annee_modif_plant");
input8=lookup_widget(Modifier_plante,"sb_nombre_modif_plant");

gtk_entry_set_text (GTK_ENTRY(input1),t.nom);
gtk_entry_set_text (GTK_ENTRY(input2),t.id);
gtk_entry_set_text (GTK_ENTRY(input3),t.type);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),t.d.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),t.d.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7),t.d.annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),t.nombre);


}


void
on_afficher_plant_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview_plant;
treeview_plant=lookup_widget(objet_graphique,"treeview_plant");
afficher_plante(treeview_plant);
}


void
on_ajouter_plant_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondeplantation;
GtkWidget *Ajouter_plante;

Ajouter_plante=create_Ajouter_plante();
gtk_widget_show(Ajouter_plante);
Gestiondeplantation=lookup_widget(objet_graphique,"Gestiondeplantation");
gtk_widget_hide(Gestiondeplantation);
}


void
on_retour_plant_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *employee,*Gestiondeplantation;
	Gestiondeplantation=lookup_widget(objet_graphique,"gestiondeplantation");
	gtk_widget_hide(Gestiondeplantation);
	employee=create_employee();
	gtk_widget_show(employee);
}


void
on_chercher_plant_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[30];
GtkWidget *input18;

input18=lookup_widget(objet_graphique,"id_plant");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input18)));
 
rechercher_plante(id);

gtk_entry_set_text(GTK_ENTRY(input18),"");
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview_plant");
afficher_plante_rechercher(treeview1);

}


void
on_retour_ajout_plant_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondeplantation;
GtkWidget *Ajouter_plante;

Gestiondeplantation=create_gestiondeplantation();
gtk_widget_show(Gestiondeplantation);
Ajouter_plante=lookup_widget(objet_graphique,"Ajouter_plante");
gtk_widget_hide(Ajouter_plante);
}


void
on_ajout_plant_ok_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
plante t;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*nombre;
GtkWidget*jour;
GtkWidget*mois;
GtkWidget*annee;
GtkWidget*sortie1;

GtkWidget *Ajouter_plante;

input1=lookup_widget(objet_graphique,"nom_ajout_plant");
input2=lookup_widget(objet_graphique,"id_ajout_plant");
input3=lookup_widget(objet_graphique,"type_ajout_plant");
input4=lookup_widget(objet_graphique,"cb_saison_ajout_plant");
jour=lookup_widget(objet_graphique,"sb_jour_ajout_plant");
mois=lookup_widget(objet_graphique,"sb_mois_ajout_plant");
annee=lookup_widget(objet_graphique,"sb_annee_ajout_plant");
nombre=lookup_widget(objet_graphique,"sb_nombre_ajout_plant");


sortie1=lookup_widget(objet_graphique,"label169");

strcpy(t.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(t.saison,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
t.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
t.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
t.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
t.nombre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombre));
ajouter_plante(t);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie1,GTK_STATE_NORMAL,&color);

gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_label_set_text(GTK_LABEL(sortie1),"ajout effectué avec succes");

}


void
on_retour_modifier_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondeplantation;
GtkWidget *Modifier_plante;

Gestiondeplantation=create_gestiondeplantation();
gtk_widget_show(Gestiondeplantation);
Modifier_plante=lookup_widget(objet_graphique,"Modifier_plante");
gtk_widget_hide(Modifier_plante);
}


void
on_modifier_ok_plant_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
plante t;
GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*nombre;
GtkWidget*jour;
GtkWidget*mois;
GtkWidget*annee;
GtkWidget *sortie2;
GtkWidget *Modifier_plante;

Modifier_plante=lookup_widget(objet_graphique,"Modifier_plante");
input1=lookup_widget(Modifier_plante,"id_modif_plant");
input2=lookup_widget(Modifier_plante,"nom_modif_plant");
input3=lookup_widget(Modifier_plante,"type_modif_plant");
input4=lookup_widget(Modifier_plante,"cb_saison_modif_plant");
jour=lookup_widget(Modifier_plante,"sb_jour_modif_plant");
mois=lookup_widget(Modifier_plante,"sb_mois_modif_plant");
annee=lookup_widget(Modifier_plante,"sb_annee_modif_plant");
nombre=lookup_widget(Modifier_plante,"sb_nombre_modif_plant");

sortie2=lookup_widget(objet_graphique,"label181");

strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(t.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(t.saison,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
t.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
t.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
t.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
t.nombre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombre));

modifier_plante(t);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie2,GTK_STATE_NORMAL,&color);
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_label_set_text(GTK_LABEL(sortie2),"Modification effectué avec succes");
}


void
on_retour_supprimer_plant_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondeplantation;
GtkWidget *Supprimer_plante;

Gestiondeplantation=create_gestiondeplantation();
gtk_widget_show(Gestiondeplantation);
Supprimer_plante=lookup_widget(objet_graphique,"Supprimer_plante");
gtk_widget_hide(Supprimer_plante);
}


void
on_supp_ok_plant_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *sortie3;
char id[30];
input1=lookup_widget(objet_graphique,"id_supp_plant");
sortie3=lookup_widget(objet_graphique,"label186");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
  
supprimer_plante(id);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie3,GTK_STATE_NORMAL,&color);
gtk_entry_set_text(GTK_ENTRY(input1), "");
gtk_label_set_text(GTK_LABEL(sortie3),"Suppression effectué avec succes");
}


void
on_treeview_annee_seche_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* annee;
	gfloat* temperature;

	annees a;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &annee,1,&temperature,-1);
	strcpy(a.annee,annee);
	a.temperature=*temperature;

	}
}


void
on_annee_plus_seche_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestion_annee_la_plus_seche;
	gestion_annee_la_plus_seche=lookup_widget(objet_graphique,"gestion_annee_la_plus_seche");
	annee_la_plus_seche();
	GtkWidget *treeview1;
	treeview1=lookup_widget(objet_graphique,"treeview_annee_seche");
	afficher_annee_seche(treeview1);
}


void
on_ajouter_annee_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_annee_la_plus_seche;
GtkWidget *ajouter_annees;

ajouter_annees=create_ajouter_annees();
gtk_widget_show(ajouter_annees);
gestion_annee_la_plus_seche=lookup_widget(objet_graphique,"gestion_annee_la_plus_seche");
gtk_widget_hide(gestion_annee_la_plus_seche);
}


void
on_afficher_annee_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview_annee_seche");
afficher_annee(treeview1);
}


void
on_supprimer_annee_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_annee_la_plus_seche;
GtkWidget *supprimer_annees;

supprimer_annees=create_supprimer_annees();
gtk_widget_show(supprimer_annees);
gestion_annee_la_plus_seche=lookup_widget(objet_graphique,"gestion_annee_la_plus_seche");
gtk_widget_hide(gestion_annee_la_plus_seche);
}


void
on_ajouter_annee_ok_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
annees a;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget *ajouter_annees;
GtkWidget*sortie4;
input1=lookup_widget(objet_graphique,"entry_annee_ajout");
input2=lookup_widget(objet_graphique,"entry_temp_moyenne");
sortie4=lookup_widget(objet_graphique,"label195");

strcpy(a.annee,gtk_entry_get_text(GTK_ENTRY(input1)));
a.temperature=atof(gtk_entry_get_text(GTK_ENTRY(input2)));

ajouter_annee(a);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie4,GTK_STATE_NORMAL,&color);
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_label_set_text(GTK_LABEL(sortie4),"ajout effectué avec succes");
}


void
on_retour_ajout_annee_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_annee_la_plus_seche;
GtkWidget *ajouter_annees;

gestion_annee_la_plus_seche=create_gestion_annee_la_plus_seche();
gtk_widget_show(gestion_annee_la_plus_seche);
ajouter_annees=lookup_widget(objet_graphique,"ajouter_annees");
gtk_widget_hide(ajouter_annees);
}


void
on_retour_supp_annee_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_annee_la_plus_seche;
GtkWidget *supprimer_annees;

gestion_annee_la_plus_seche=create_gestion_annee_la_plus_seche();
gtk_widget_show(gestion_annee_la_plus_seche);
supprimer_annees=lookup_widget(objet_graphique,"supprimer_annees");
gtk_widget_hide(supprimer_annees);
}


void
on_supp_annee_ok_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *sortie5;
char annee[10];
input1=lookup_widget(objet_graphique,"entry_annee_supp");
sortie5=lookup_widget(objet_graphique,"label197");
strcpy(annee,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_annee(annee);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie5,GTK_STATE_NORMAL,&color);
gtk_entry_set_text(GTK_ENTRY(input1), "");
gtk_label_set_text(GTK_LABEL(sortie5),"Suppression effectué avec succes");
}




