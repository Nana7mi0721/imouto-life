
void __fastcall FUN_00452450(char *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  param_1[0x808] = '\0';
  param_1[0x809] = '\0';
  param_1[0x80a] = '\0';
  param_1[0x80b] = '\0';
  param_1[8] = -1;
  param_1[9] = -1;
  param_1[10] = -1;
  param_1[0xb] = -1;
  FUN_004ce950();
  if ((((DAT_00a140a9 == '\0') &&
       (iVar1 = FUN_0046f600(*(undefined4 *)(param_1 + 0x14)), *param_1 != '\0')) &&
      (*(int *)(param_1 + 4) == 0)) && ((-1 < *(int *)(param_1 + 0x14) && (-1 < iVar1)))) {
    iVar1 = FUN_0046f600(*(undefined4 *)(param_1 + 0x14));
    if (-1 < iVar1) {
      uVar2 = FUN_004d29a0();
      uVar3 = FUN_0046f600(*(undefined4 *)(param_1 + 0x14));
      if (uVar3 < uVar2) {
        uVar4 = FUN_0046f600(*(undefined4 *)(param_1 + 0x14));
        FUN_004d2a00(uVar4);
        FUN_00487280();
      }
    }
    param_1[0x14] = -1;
    param_1[0x15] = -1;
    param_1[0x16] = -1;
    param_1[0x17] = -1;
  }
  return;
}

