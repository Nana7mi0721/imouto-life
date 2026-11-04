
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0065cf80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            float *param_6)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  
  iVar1 = param_5;
  puVar2 = (uint *)FUN_006507d0(param_5 * 8);
  if (puVar2 == (uint *)0x0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagCheckedRationalArray",
                 s_Out_of_memory_00a066e4);
    return 0;
  }
  if (param_5 != 0) {
    puVar5 = puVar2;
    do {
      if ((float)_DAT_007d0a60 < *param_6) {
        uVar3 = __ftol();
        if ((float)uVar3 == *param_6) {
          *puVar5 = uVar3;
          puVar5[1] = 1;
        }
        else if ((float)_DAT_00802e18 <= *param_6) {
          *puVar5 = 0xffffffff;
          uVar3 = __ftol();
          puVar5[1] = uVar3;
        }
        else {
          uVar3 = __ftol();
          *puVar5 = uVar3;
          puVar5[1] = 0xffffffff;
        }
      }
      else {
        *puVar5 = 0;
        puVar5[1] = 1;
      }
      param_6 = param_6 + 1;
      puVar5 = puVar5 + 2;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
    FUN_0065a6c0(puVar2,iVar1 * 2);
  }
  uVar4 = FUN_0065d3a0(param_1,param_2,param_3,param_4,5,iVar1,iVar1 * 8,puVar2);
  FUN_006507e0(puVar2);
  return uVar4;
}

