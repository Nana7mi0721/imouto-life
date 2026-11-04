
undefined4 FUN_0052ce00(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  longlong lVar4;
  undefined4 uStack_4;
  
  lVar4 = (**(code **)(unaff_ESI + 0x34))(*(undefined4 *)(unaff_ESI + 0x4c));
  if (lVar4 == 0) {
    uVar2 = (**(code **)(unaff_ESI + 0x3c))(&uStack_4,1,3,*(undefined4 *)(unaff_ESI + 0x4c));
    iVar3 = (**(code **)(unaff_ESI + 0x44))(*(undefined4 *)(unaff_ESI + 0x4c));
    uVar1 = uStack_4;
    while (iVar3 == 0) {
      uStack_4 = uVar1;
      FUN_0056da20(0);
      iVar3 = (**(code **)(unaff_ESI + 0x44))(*(undefined4 *)(unaff_ESI + 0x4c));
      uVar1 = uStack_4;
    }
    if (uVar2 == 0) {
      return 0xffffffff;
    }
    uStack_4._1_1_ = (char)((uint)uVar1 >> 8);
    uStack_4._0_1_ = (char)uVar1;
    if (1 < uVar2) {
      if ((char)uStack_4 == -1) {
        if (uStack_4._1_1_ == -2) {
          *(undefined4 *)(unaff_ESI + 0x50) = 0x4b0;
          (**(code **)(unaff_ESI + 0x38))(*(undefined4 *)(unaff_ESI + 0x4c),2,0,0);
          return 0;
        }
      }
      else if (((char)uStack_4 == -2) && (uStack_4._1_1_ == -1)) {
        *(undefined4 *)(unaff_ESI + 0x50) = 0x4b1;
        (**(code **)(unaff_ESI + 0x38))(*(undefined4 *)(unaff_ESI + 0x4c),2,0,0);
        return 0;
      }
    }
    if ((((2 < uVar2) && ((char)uStack_4 == -0x11)) && (uStack_4._1_1_ == -0x45)) &&
       (uStack_4._2_1_ = (char)((uint)uVar1 >> 0x10), uStack_4._2_1_ == -0x41)) {
      *(undefined4 *)(unaff_ESI + 0x50) = 0xfde9;
      (**(code **)(unaff_ESI + 0x38))(*(undefined4 *)(unaff_ESI + 0x4c),3,0,0);
      return 0;
    }
    (**(code **)(unaff_ESI + 0x38))(*(undefined4 *)(unaff_ESI + 0x4c),0,0,0);
  }
  return 0;
}

