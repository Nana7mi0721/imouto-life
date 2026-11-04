
longlong FUN_006515a0(int param_1)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((*(int *)(param_1 + 0x48) == 0) || (*(int *)(param_1 + 0x44) == 0)) {
    return 0;
  }
  uVar2 = FUN_00650b30(param_1,*(undefined2 *)(param_1 + 0x54),0,*(int *)(param_1 + 0x44),0,
                       s_TIFFTileRowSize_00a06c7c);
  uVar1 = (uint)uVar2;
  if (*(short *)(param_1 + 0x7e) == 1) {
    uVar1 = FUN_00650b30(param_1,uVar2,*(undefined2 *)(param_1 + 0x62),0,s_TIFFTileRowSize_00a06c7c)
    ;
  }
  if ((uVar1 & 7) == 0) {
    lVar3 = __aullshr();
    return lVar3;
  }
  lVar3 = __aullshr();
  return lVar3 + 1;
}

