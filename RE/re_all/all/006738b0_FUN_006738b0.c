
void FUN_006738b0(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else if ((*(uint *)(param_1 + 0x74) & 6) != 0) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
    return;
  }
  if (param_3 != 0x20) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_invalid_00a0cdac);
    return;
  }
  FUN_00673110(param_1,local_20,0x20);
  iVar2 = FUN_00673140(param_1,0);
  if (iVar2 == 0) {
    local_28 = FUN_006736c0(0,local_20);
    local_24 = FUN_006736c0(0,local_1c);
    local_40 = FUN_006736c0(0,local_18);
    local_3c = FUN_006736c0(0,local_14);
    local_38 = FUN_006736c0(0,local_10);
    local_34 = FUN_006736c0(0,local_c);
    local_30 = FUN_006736c0(0,local_8);
    local_2c = FUN_006736c0(0,local_4);
    if (((((local_28 == -1) || (local_24 == -1)) || (local_40 == -1)) ||
        ((local_3c == -1 || (local_38 == -1)))) ||
       ((local_34 == -1 || ((local_30 == -1 || (local_2c == -1)))))) {
      FUN_00668b90(param_1,s_invalid_values_00a0ce54);
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x326);
      if ((uVar1 & 0x8000) == 0) {
        if ((uVar1 & 0x10) == 0) {
          *(ushort *)(param_1 + 0x326) = uVar1 | 0x10;
          FUN_00669a00(param_1,param_1 + 0x2dc,&local_40,1);
          FUN_006699d0(param_1,param_2);
          return;
        }
        *(ushort *)(param_1 + 0x326) = uVar1 | 0x8000;
        FUN_006699d0(param_1,param_2);
        FUN_00668b90(param_1,s_duplicate_00a0bdf4);
        return;
      }
    }
  }
  return;
}

