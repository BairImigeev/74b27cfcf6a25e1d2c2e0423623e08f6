#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int printpicture(FILE *file) 
{  
   char str[1000];
   char *estr; 
   while (1)
   {
    estr = fgets (str,sizeof(str), file);

    if (estr == NULL)
      {
       if ( feof (file) != 0)
           {  
            printf ("\n");
            break;
           }
       else
           {
             printf ("\n error read file \n");
             break;
           }
      }
      printf ("%s",str);  
    }
  return 0;
}

static int help_flag;

int main (int argc, char **argv)
{
  int c;
  FILE * file; 
  while (1)
    {
      static struct option long_options[] =
        {
          {"help", no_argument, &help_flag, 1},
          {"print_animal", 0, 0, 'a'},
          {"print_car", 0, 0, 'c'},
          {"print_human", 0, 0, 'h'},
          {0, 0, 0, 0}
        };
      int option_index = 0;
      c = getopt_long (argc, argv, "ach",
                       long_options, &option_index);

      if (c == -1)
        break;

      switch (c)
        {
        case 0:
          if (long_options[option_index].flag != 0)
              break;
        case 'a':
            file = fopen("animal.txt","r");
            printpicture(file);
            break;

        case 'c':
            file = fopen("car.txt","r");
            printpicture(file);
            break;

        case 'h':
            file=fopen("human.txt","r");
            printpicture(file);
            break;
          
        case '?':
          break;

        default:
          abort ();
        }
    }

  if (help_flag)
    {
     printf("-a  --print_animal\n");
     printf("-h  --print_human\n");
     printf("-c  --print_car\n");
    }
  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }
  exit (0);
}
