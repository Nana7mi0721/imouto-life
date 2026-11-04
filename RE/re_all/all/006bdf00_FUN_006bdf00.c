
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006bdf00(int param_1,undefined4 param_2,int param_3)

{
  longlong lVar1;
  
  if (param_3 < 0) {
    return (float10)_DAT_00805148;
  }
  lVar1 = FUN_006bde70(param_1,param_2,param_3);
  return ((float10)*(uint *)(param_1 + 0x20) / (float10)*(uint *)(param_1 + 0x1c)) *
         (float10)(lVar1 + 1);
}

