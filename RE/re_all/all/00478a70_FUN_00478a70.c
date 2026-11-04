
void __thiscall FUN_00478a70(int param_1,char param_2)

{
  char cVar1;
  
  if (param_2 != '\0') {
    FUN_004785a0();
  }
  cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),4);
  if (cVar1 != '\0') {
    FUN_004785a0();
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0xb4);
    FUN_004784d0();
    if (*(char *)(param_1 + 0x54) != '\0') {
      FUN_004465e0(4);
    }
    *(undefined4 *)(param_1 + 0x118) = 4;
  }
  return;
}

