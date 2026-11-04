
undefined4 FUN_00673070(int param_1)

{
  undefined4 uVar1;
  undefined1 local_c [4];
  undefined1 local_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  byte bStack_5;
  
  *(undefined4 *)(param_1 + 0x2c4) = 0x21;
  FUN_00668560(param_1,local_c,8);
  uVar1 = FUN_00672f80(param_1,local_c);
  *(uint *)(param_1 + 0x11c) =
       (((CONCAT12(uStack_6,CONCAT11(uStack_7,local_8)) & 0xff) << 8 |
        CONCAT12(bStack_5,CONCAT11(uStack_6,uStack_7)) & 0xff) << 8 |
       CONCAT11(bStack_5,uStack_6) & 0xff) << 8 | (uint)bStack_5;
  FUN_00668f30(param_1);
  FUN_00668f50(param_1,&local_8,4);
  FUN_00675eb0(param_1,*(undefined4 *)(param_1 + 0x11c));
  *(undefined4 *)(param_1 + 0x2c4) = 0x41;
  return uVar1;
}

