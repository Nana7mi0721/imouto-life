
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00660ba0(int param_1,short *param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int local_10;
  
  puVar3 = *(uint **)(param_1 + 0xc);
  if (0 < param_3) {
    local_10 = param_3;
    do {
      sVar1 = *param_2;
      if (sVar1 < 1) {
        iVar4 = 0;
      }
      else if (sVar1 < 0x1cf2) {
        if (*(int *)(param_1 + 4) == 0) {
          iVar4 = sVar1 + -0xcf2 >> 2;
        }
        else {
          _rand();
          iVar4 = __ftol();
        }
      }
      else {
        iVar4 = 0x3ff;
      }
      uVar2 = FUN_0065eb60(((double)(int)param_2[1] + _DAT_00804a60) * _DAT_00805410,
                           ((double)(int)param_2[2] + _DAT_00804a60) * _DAT_00805410,
                           *(undefined4 *)(param_1 + 4));
      if ((int)uVar2 < 0) {
        uVar2 = FUN_0065eb60(0xbd156c1a,0x3fcaf286,0x94b8199e,0x3fde50d7,0);
      }
      *puVar3 = iVar4 << 0xe | uVar2;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 3;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  return;
}

