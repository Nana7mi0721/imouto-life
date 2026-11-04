
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0065d0d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            float *param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  float *pfVar5;
  
  pfVar5 = param_6;
  piVar1 = (int *)FUN_006507d0(param_5 * 8);
  if (piVar1 == (int *)0x0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagCheckedSrationalArray",
                 s_Out_of_memory_00a066e4);
    return 0;
  }
  if (param_5 != 0) {
    param_6 = (float *)param_5;
    piVar4 = piVar1;
    do {
      if ((float)_DAT_007d0a60 <= *pfVar5) {
        iVar2 = __ftol();
        if ((float)iVar2 == *pfVar5) {
          *piVar4 = iVar2;
          piVar4[1] = 1;
        }
        else {
          if ((float)_DAT_00802e18 <= *pfVar5) {
            *piVar4 = 0x7fffffff;
            goto LAB_0065d1ec;
          }
          iVar2 = __ftol();
          *piVar4 = iVar2;
          piVar4[1] = 0x7fffffff;
        }
      }
      else {
        iVar2 = __ftol();
        if ((float)iVar2 == *pfVar5) {
          *piVar4 = iVar2;
          piVar4[1] = 1;
        }
        else if (*pfVar5 <= (float)_DAT_00805148) {
          *piVar4 = -0x7fffffff;
LAB_0065d1ec:
          iVar2 = __ftol();
          piVar4[1] = iVar2;
        }
        else {
          iVar2 = __ftol();
          *piVar4 = iVar2;
          piVar4[1] = 0x7fffffff;
        }
      }
      pfVar5 = pfVar5 + 1;
      piVar4 = piVar4 + 2;
      param_6 = (float *)((int)param_6 + -1);
    } while (param_6 != (float *)0x0);
  }
  if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
    FUN_0065a6c0(piVar1,param_5 * 2);
  }
  uVar3 = FUN_0065d3a0(param_1,param_2,param_3,param_4,10,param_5,param_5 * 8,piVar1);
  FUN_006507e0(piVar1);
  return uVar3;
}

