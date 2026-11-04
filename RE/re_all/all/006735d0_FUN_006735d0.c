
void FUN_006735d0(int param_1,undefined4 param_2,int param_3)

{
  if (((*(uint *)(param_1 + 0x74) & 1) == 0) || ((*(uint *)(param_1 + 0x74) & 4) == 0)) {
    FUN_00668a30(param_1,s_out_of_place_00a0cdb4);
  }
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0x18;
  FUN_00673140(param_1,param_3);
  if (param_3 != 0) {
    FUN_00668b90(param_1,s_invalid_00a0cdac);
  }
  return;
}

