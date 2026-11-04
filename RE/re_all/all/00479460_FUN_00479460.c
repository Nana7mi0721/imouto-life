
void __thiscall FUN_00479460(int param_1,char param_2)

{
  char cVar1;
  
  if (param_2 != '\0') {
    FUN_00478680();
  }
  cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),8);
  if ((((cVar1 == '\0') ||
       (cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),
                             *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0xb4),6), cVar1 == '\0'))
      || (cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),6),
         cVar1 == '\0')) ||
     (cVar1 = FUN_00442730(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0xb4),
                           *(undefined4 *)(param_1 + 0x2c),8), cVar1 == '\0')) {
    if (((*(int *)(param_1 + 0x118) == 8) ||
        ((*(char *)(param_1 + 0xba) == '\0' && (*(char *)(param_1 + 0xbb) == '\0')))) ||
       (cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),8),
       cVar1 == '\0')) {
      if (((*(char *)(param_1 + 0xba) == '\0') && (*(char *)(param_1 + 0xbb) == '\0')) ||
         (cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),6),
         cVar1 == '\0')) {
        if (((*(char *)(param_1 + 0xba) != '\0') || (*(char *)(param_1 + 0xbb) != '\0')) &&
           (cVar1 = FUN_00442730(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),8),
           cVar1 != '\0')) {
          *(undefined4 *)(param_1 + 0x118) = 8;
          FUN_00478680();
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0xb4);
          FUN_004784d0();
          if (*(char *)(param_1 + 0x54) != '\0') {
            FUN_004465e0(8);
          }
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x118) = 6;
        FUN_00478680();
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0xb4);
        FUN_004784d0();
        if (*(char *)(param_1 + 0x54) != '\0') {
          FUN_004465e0(6);
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x118) = 8;
      FUN_00478680();
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0xb4);
      FUN_004784d0();
      if (*(char *)(param_1 + 0x54) != '\0') {
        FUN_004465e0(8);
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x118) = 9;
    FUN_00478680();
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0xb4);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0xb4);
    FUN_004784d0();
    if (*(char *)(param_1 + 0x54) != '\0') {
      FUN_004465e0(9);
    }
  }
  return;
}

