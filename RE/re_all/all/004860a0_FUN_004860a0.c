
void __thiscall FUN_004860a0(int param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),2);
  if (cVar1 != '\0') {
    iVar2 = FUN_004789a0(0,0);
    if (iVar2 == 0) {
      iVar2 = FUN_004789a0(1,0);
      if (iVar2 == 0) goto LAB_00486105;
    }
  }
  FUN_00447350(*(undefined4 *)(param_1 + 0x28),*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0xb4));
LAB_00486105:
  FUN_00443aa0(param_2);
  return;
}

