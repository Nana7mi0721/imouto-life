
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00452970(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auStack_64 [72];
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined *puStack_14;
  undefined4 local_10;
  int local_c;
  undefined1 *local_8;
  
  puStack_14 = &DAT_007cedaf;
  puStack_18 = &DAT_00a13fc0;
  uStack_1c = 0x452988;
  cVar1 = operator!=<>();
  if (cVar1 == '\0') {
    puStack_14 = &DAT_007cedb0;
    puStack_18 = &DAT_00a14014;
    uStack_1c = 0x4529a1;
    cVar1 = operator!=<>();
    if (cVar1 == '\0') {
      DAT_00a140c5 = 1;
      _DAT_00a14034 = 0;
      DAT_00a14090 = 0;
      DAT_00a14091 = 0;
      puStack_14 = *(undefined **)(local_c + 8);
      puStack_18 = (undefined *)0x4529e3;
      uVar2 = FUN_004cecd0();
      local_8 = auStack_64;
      local_10 = FUN_00487300(uVar2);
      FUN_00450200();
      return 1;
    }
  }
  return 0;
}

