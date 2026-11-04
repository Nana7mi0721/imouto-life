
undefined4 FUN_0059d030(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  short *psVar4;
  int iVar5;
  
  iVar1 = FUN_005d38a0((int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 4),
                       *(undefined4 *)(param_1 + 8),2,param_1 + 0x14,0);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_0056ddb0();
  uVar3 = FUN_0056ddb0(uVar2 >> 10);
  uVar3 = FUN_0056ddc0(uVar3);
  FUN_0056bca0(&DAT_007fc0e8,iVar1,(int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 4),
               *(undefined4 *)(param_1 + 8),uVar3);
  if (DAT_00ee230d == '\0') {
    DAT_00ee230d = '\x01';
    uVar2 = FUN_0056ddb0();
    uVar3 = FUN_0056ddb0(uVar2 >> 10);
    uVar3 = FUN_0056ddc0(uVar3);
    FUN_0056bca0(&DAT_007fc010,iVar1,(int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 4),
                 *(undefined4 *)(param_1 + 8),uVar3);
    FUN_0056bca0(&DAT_007fbfc8,DAT_00ecfb18);
    iVar1 = 0;
    iVar5 = 0;
    if (0 < DAT_00edbb1c) {
      psVar4 = &DAT_00ecfb20;
      do {
        if ((char)psVar4[-2] != '\0') {
          iVar1 = iVar1 + 1;
          FUN_0056bc50(L"No%d. UseFlag:%d UseCount:%d SizeX:%d SizeY:%d Format:%d",iVar5,
                       *(undefined1 *)((int)psVar4 + -3),*(undefined4 *)(psVar4 + 4),(int)psVar4[-1]
                       ,(int)*psVar4,*(undefined4 *)(psVar4 + 2));
        }
        iVar5 = iVar5 + 1;
        psVar4 = psVar4 + 0xc;
      } while (iVar1 < DAT_00edbb1c);
    }
  }
  return 0xffffffff;
}

