
void __thiscall FUN_00486420(int param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),9);
  if (cVar1 != '\0') {
    iVar2 = FUN_004789a0(0,0);
    if (iVar2 == 0) {
      iVar2 = FUN_004789a0(1,0);
      if (iVar2 == 0) goto LAB_0048648e;
    }
  }
  FUN_00447350(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0xb4),
               *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0xb4));
LAB_0048648e:
  FUN_00479460(param_2);
  return;
}

