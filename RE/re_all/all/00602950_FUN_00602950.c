
int FUN_00602950(int param_1,int *param_2)

{
  void *pvVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b275b;
  local_c = ExceptionList;
  if (param_2 == (int *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x14);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00602a90(param_1 + -0xc,0);
  }
  *param_2 = iVar2;
  ExceptionList = local_c;
  return (-(uint)(iVar2 != 0) & 0x7ff8fff2) + 0x8007000e;
}

