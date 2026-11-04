
void FUN_00674b50(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 local_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 local_4;
  
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else {
    if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
      return;
    }
    if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x80) != 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_duplicate_00a0bdf4);
      return;
    }
  }
  if (param_3 != 9) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_invalid_00a0cdac);
    return;
  }
  FUN_00673110(param_1,&local_c,9);
  iVar1 = FUN_00673140(param_1,0);
  if (iVar1 == 0) {
    FUN_00672610(param_1,param_2,
                 (((CONCAT12(uStack_a,CONCAT11(uStack_b,local_c)) & 0xff) * 0x100 +
                  (CONCAT12(uStack_9,CONCAT11(uStack_a,uStack_b)) & 0xff)) * 0x100 +
                 (CONCAT12(local_8,CONCAT11(uStack_9,uStack_a)) & 0xff)) * 0x100 +
                 (CONCAT12(uStack_7,CONCAT11(local_8,uStack_9)) & 0xff),
                 (((CONCAT12(uStack_6,CONCAT11(uStack_7,local_8)) & 0xff) * 0x100 +
                  (CONCAT12(uStack_5,CONCAT11(uStack_6,uStack_7)) & 0xff)) * 0x100 +
                 (CONCAT12(local_4,CONCAT11(uStack_5,uStack_6)) & 0xff)) * 0x100 +
                 (CONCAT11(local_4,uStack_5) & 0xff),local_4);
  }
  return;
}

