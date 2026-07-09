//学生信息 
struct student
{
	char number[20];
	char name[50];
	double math;
	double english;
	double cs;
};

//结点信息 
struct node
{
	struct student data;
	struct node *next;
};

int Login();
void Menu();
void Input(struct node* L);
void Basic(struct node* L);
void Score(struct node* L);
void Add(struct node* L);
void Delete(struct node* L);
void Show(struct node* L);
void SaveFile(struct node* L);
void ReadFile(struct node* L);
void Modify(struct node* L);
void ShowMath(struct node* L); 
void ShowEnglish(struct node* L); 
void ShowCs(struct node* L);
void MathGrade(struct node* L);
void EnglishGrade(struct node* L);
void CsGrade(struct node* L);
void Grade(struct node* L);
void Search(struct node* L);
void Failed(struct node* L);
