
int FUN_0055bc20(int param_1)

{
  int in_EAX;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined1 local_10 [16];
  
  local_14 = in_EAX >> 0x1f;
  local_20 = 1000;
  local_1c = 0;
  local_18 = in_EAX;
  FUN_0056d6c0(&local_18,&local_20,local_10);
  local_1c = param_1 >> 0x1f;
  local_20 = param_1;
  FUN_0056d730(local_10,&local_20,&local_18);
  return local_18;
}

