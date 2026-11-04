
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0078fd00(int *param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  
  pfVar1 = (float *)(**(code **)(*param_1 + 0x18))();
  if (_DAT_00804520 <
      (pfVar1[1] - param_2[1]) * (pfVar1[1] - param_2[1]) +
      (pfVar1[2] - param_2[2]) * (pfVar1[2] - param_2[2]) +
      (*pfVar1 - *param_2) * (*pfVar1 - *param_2)) {
    FUN_00791740(param_2);
    if (*(char *)((int)param_1 + 0x39) != '\0') {
      (*(code *)**(undefined4 **)param_1[0xd])(0);
      FUN_00646b80(param_1[0xd]);
    }
    iVar2 = FUN_00646b30(0xac,0x10);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00791d00();
    }
    param_1[0xd] = iVar2;
    FUN_00791d30(param_1[0xc],CONCAT31((int3)((uint)(param_1 + 8) >> 8),(char)param_1[0xe]),
                 param_1 + 4,param_1 + 8);
    *(undefined1 *)((int)param_1 + 0x39) = 1;
  }
  return;
}

