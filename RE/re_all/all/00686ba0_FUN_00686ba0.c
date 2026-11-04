
void FUN_00686ba0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x188);
  FUN_00686af0(param_1,0xd8);
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  if (*(char *)(param_1 + 0xe8) != '\0') {
    FUN_00686bf0(param_1);
  }
  if (*(char *)(param_1 + 0xf0) != '\0') {
    FUN_00686ca0(param_1);
  }
  return;
}

