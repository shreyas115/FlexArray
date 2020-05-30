/* FlexArray.h */
extern char* CreateFlexArray();
extern void AddElement( void* value, char* type);
extern void* GetElement(int index);
extern char* GetType(int index);
extern void* DeleteElement(int index);
		