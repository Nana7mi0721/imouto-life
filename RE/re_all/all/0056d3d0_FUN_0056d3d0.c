
bool FUN_0056d3d0(char *param_1,char *param_2,int param_3)

{
  bool bVar1;
  
  if (param_3 == 0) {
    return false;
  }
  bVar1 = true;
  do {
    if (param_3 == 0) break;
    param_3 = param_3 + -1;
    bVar1 = *param_1 == *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (bVar1);
  return !bVar1;
}

