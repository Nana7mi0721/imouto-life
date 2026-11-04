
void FUN_00675280(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 local_10 [2];
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_8 [2];
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
  if ((*(byte *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else if ((param_2 != 0) && ((*(uint *)(param_2 + 8) & 0x200) != 0)) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_duplicate_00a0bdf4);
    return;
  }
  if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 8;
  }
  if (param_3 != 7) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_invalid_00a0cdac);
    return;
  }
  FUN_00673110(param_1,local_10,7);
  iVar1 = FUN_00673140(param_1,0);
  if (iVar1 == 0) {
    local_2 = local_a;
    local_3 = local_b;
    local_4 = local_c;
    local_5 = local_d;
    local_6 = local_e;
    FUN_00672aa0(param_1,param_2,local_8);
  }
  return;
}

