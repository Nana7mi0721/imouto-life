
undefined4 FUN_00606410(undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  void *unaff_EDI;
  undefined4 unaff_retaddr;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar3 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b281b;
  local_c = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  param_1 = (undefined4 *)0x0;
  ExceptionList = &local_c;
  *puVar3 = 0;
  pvVar1 = operator_new(100);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00607ce0(0,0,&param_1);
  }
  local_4 = 0xffffffff;
  if (piVar2 == (int *)0x0) {
    ExceptionList = local_c;
    return 0x8007000e;
  }
  if ((int)param_1 < 0) {
    (**(code **)(*piVar2 + 0xc))(1);
    ExceptionList = pvVar1;
    return unaff_retaddr;
  }
  puStack_8 = (undefined1 *)(**(code **)piVar2[3])(piVar2 + 3,&DAT_0085e8d4);
  if ((int)puStack_8 < 0) {
    (**(code **)(*piVar2 + 0xc))(1);
    ExceptionList = puVar3;
    return 0x80004002;
  }
  ExceptionList = unaff_EDI;
  return 0;
}

