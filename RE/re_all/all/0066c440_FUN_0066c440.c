
void FUN_0066c440(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = param_1;
  if (param_1 != 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x40) == 0) {
      iVar3 = FUN_0066cc40(param_1);
      FUN_0066c000(param_1);
    }
    else {
      if ((*(char *)(param_1 + 0x154) != '\0') && ((*(byte *)(param_1 + 0x7c) & 2) == 0)) {
        FUN_006687b0(param_1,s_Interlace_handling_should_be_tur_00a0c5c4);
        *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x104);
      }
      iVar3 = FUN_0066cc40(param_1);
    }
    iVar1 = *(int *)(param_1 + 0x104);
    if (0 < iVar3) {
      param_1 = iVar3;
      do {
        if (iVar1 != 0) {
          iVar3 = iVar1;
          puVar4 = param_2;
          do {
            FUN_0066c030(iVar2,*puVar4,0);
            puVar4 = puVar4 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}

