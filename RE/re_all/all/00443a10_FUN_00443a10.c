
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00443a10(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0xad) == '\0') {
    if (*(short *)(param_1 + 0x4a) != *(short *)(param_1 + 0x4c)) {
      *(double *)(param_1 + 0x140) = (double)DAT_0084b244 + *(double *)(param_1 + 0x140);
    }
  }
  else {
    *(double *)(param_1 + 0x140) =
         (double)DAT_0084b244 * _DAT_007d0a70 + *(double *)(param_1 + 0x140);
  }
  if ((*(char *)(param_1 + 0x57) == '\0') || (cVar1 = FUN_004783f0(), cVar1 != '\0')) {
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + DAT_0084b244;
    return;
  }
  return;
}

