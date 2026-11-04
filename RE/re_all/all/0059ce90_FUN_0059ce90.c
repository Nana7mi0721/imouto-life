
undefined4 FUN_0059ce90(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 2) == '\0') {
    iVar1 = FUN_005d36d0((int)*(short *)(param_1 + 4),(int)*(short *)(param_1 + 6),
                         *(undefined1 *)(param_1 + 3),0x200,*(undefined4 *)(param_1 + 8),2,
                         param_1 + 0x14,0);
    if (iVar1 != 0) {
      uVar2 = FUN_0056ddb0();
      uVar2 = FUN_0056ddb0(uVar2);
      uVar2 = FUN_0056ddc0(uVar2);
      FUN_0056bca0(&DAT_007fbdb0,iVar1,(int)*(short *)(param_1 + 4),(int)*(short *)(param_1 + 6),
                   *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 8) * 4),uVar2);
      if (DAT_00ee230c == '\0') {
        DAT_00ee230c = '\x01';
        uVar2 = FUN_0056ddb0();
        uVar2 = FUN_0056ddb0(uVar2);
        uVar2 = FUN_0056ddc0(uVar2);
        FUN_0056bca0(&DAT_007fbdb0,iVar1,(int)*(short *)(param_1 + 4),(int)*(short *)(param_1 + 6),
                     *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 8) * 4),uVar2);
        FUN_0056bca0(&DAT_007fbd68,DAT_00ecfb18);
        iVar1 = 0;
        iVar4 = 0;
        if (0 < DAT_00ecfb18) {
          puVar3 = &DAT_00ec3b1b;
          do {
            if (puVar3[-3] != '\0') {
              iVar1 = iVar1 + 1;
              FUN_0056bc50(L"No%d. UseFlag:%d UseCount:%d CubeMap:%d SizeX:%d SizeY:%d MipMapCount:%d Format:%d"
                           ,iVar4,puVar3[-2],*(undefined4 *)(puVar3 + 9),puVar3[-1],
                           (int)*(short *)(puVar3 + 1),(int)*(short *)(puVar3 + 3),*puVar3,
                           *(undefined4 *)(puVar3 + 5));
            }
            iVar4 = iVar4 + 1;
            puVar3 = puVar3 + 0x18;
          } while (iVar1 < DAT_00ecfb18);
        }
      }
      return 0xffffffff;
    }
  }
  else {
    iVar1 = FUN_005d3750((int)*(short *)(param_1 + 4),*(undefined1 *)(param_1 + 3),0x200,
                         *(undefined4 *)(param_1 + 8),2,param_1 + 0x14);
    if (iVar1 != 0) {
      uVar2 = FUN_0056ddb0();
      uVar2 = FUN_0056ddb0(uVar2);
      uVar2 = FUN_0056ddc0(uVar2);
      FUN_0056bca0(&DAT_007fbe78,iVar1,(int)*(short *)(param_1 + 4),(int)*(short *)(param_1 + 6),
                   *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 8) * 4),uVar2);
      return 0xffffffff;
    }
  }
  return 0;
}

