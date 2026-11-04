
void __thiscall FUN_00478b90(int param_1,char param_2)

{
  char cVar1;
  
  if (param_2 != '\0') {
    FUN_00478700();
  }
  cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),8);
  if (cVar1 != '\0') {
    FUN_00478700();
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0xb4);
    FUN_004784d0();
    if (*(char *)(param_1 + 0x54) != '\0') {
      FUN_004465e0(8);
    }
    *(undefined4 *)(param_1 + 0x118) = 8;
  }
  return;
}

