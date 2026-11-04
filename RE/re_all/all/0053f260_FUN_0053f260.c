
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0053f260(int param_1,int param_2,double param_3,double param_4,double param_5,double param_6,
            double param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
            undefined4 param_11,undefined4 param_12,undefined4 param_13)

{
  int iVar1;
  float fVar2;
  ushort in_FPUControlWord;
  undefined4 in_stack_ffffff90;
  undefined2 uVar3;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_60;
  float local_5c;
  double local_58;
  undefined8 local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [24];
  
  uVar3 = (undefined2)((uint)in_stack_ffffff90 >> 0x10);
  FUN_0053e820(param_11,param_8,param_9,param_10,param_12,param_13,&local_50,&local_60);
  FUN_00581340(local_18,local_58._0_4_,0,0,local_20,local_1c);
  DAT_00a38198 = local_34;
  DAT_00a38194 = local_38;
  DAT_00a3819c = local_30;
  DAT_00a381a0 = local_2c;
  FUN_005811b0(&local_38);
  local_5c = (float)param_7;
  if (local_5c != 0.0) {
    local_58._0_4_ = ((float)(int)local_50 * (float)_DAT_00804a60 - (float)param_5) * (float)param_3
    ;
    local_64 = ((float)_DAT_00804a60 * (float)local_50._4_4_ - (float)param_6) * (float)param_4;
    FUN_0056d4d0(local_5c,&local_68,&local_6c);
    fVar2 = local_64 * local_68;
    local_64 = (float)(int)ROUND(local_6c * local_64 + local_58._0_4_ * local_68 + (float)param_2);
    iVar1 = (int)ROUND((float)param_1 + (local_58._0_4_ * local_6c - fVar2));
    local_58 = (double)CONCAT44(local_58._4_4_,iVar1);
    local_50 = (double)CONCAT44(local_50._4_4_,(float)param_3);
    FUN_00748330(DAT_00a37e58,local_18,iVar1,local_64,local_5c,(float)param_3,(float)param_4,1,0,0,
                 DAT_00a37e5c,in_FPUControlWord,in_FPUControlWord | 0xc00,in_FPUControlWord | 0xc00)
    ;
    _DAT_00a38114 = local_60;
    return 0;
  }
  if ((param_3 == 1.0) && (param_4 == 1.0)) {
    local_68 = (float)(int)ROUND((double)param_2 - param_6);
    local_50 = (double)param_1 - param_5;
    local_64 = (float)(int)ROUND(local_50);
    FUN_006c8cc0(DAT_00a37e58,local_18,local_64,local_68,1,DAT_00a37e5c,in_FPUControlWord | 0xc00,
                 in_FPUControlWord,in_FPUControlWord,CONCAT22(uVar3,in_FPUControlWord) | 0xc00);
    _DAT_00a38114 = local_60;
    return 0;
  }
  local_48 = (int)ROUND((double)param_1 - param_3 * param_5);
  local_44 = (int)ROUND((double)param_2 - param_4 * param_6);
  local_58 = (double)(int)local_50 * param_3 + (double)local_48;
  local_40 = (int)ROUND(local_58);
  local_50 = (double)local_50._4_4_ * param_4 + (double)local_44;
  local_64 = (float)(int)ROUND(local_50);
  local_3c = (int)local_64;
  FUN_006ea010(DAT_00a37e58,local_18,&local_48,1,DAT_00a37e5c);
  _DAT_00a38114 = local_60;
  return 0;
}

