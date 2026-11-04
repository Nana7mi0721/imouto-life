
undefined4 __fastcall FUN_004445b0(int param_1)

{
  undefined4 uVar1;
  void *_Src;
  void *_Dst;
  size_t _Size;
  int local_14;
  int local_10;
  undefined1 local_9;
  int local_8;
  
  FUN_00441a00();
  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
    DAT_00a117e4 = 1;
    uVar1 = 0;
  }
  else {
    DAT_00a0f844 = 4;
    _memcpy(&local_8,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    FUN_004d25b0(local_8);
    for (local_10 = 0; local_10 < local_8; local_10 = local_10 + 1) {
      FUN_004d2620(local_10);
      FUN_00441a00();
    }
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      uVar1 = 0;
    }
    else {
      DAT_00a0f844 = 1;
      _memcpy(&local_9,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      *(undefined1 *)(param_1 + 0x149) = local_9;
      if (DAT_00a0f828 < DAT_00a0f820 + 1) {
        DAT_00a117e4 = 1;
        uVar1 = 0;
      }
      else {
        DAT_00a0f844 = 1;
        _memcpy(&local_9,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        *(undefined1 *)(param_1 + 0xc0) = local_9;
        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
          DAT_00a117e4 = 1;
          uVar1 = 0;
        }
        else {
          DAT_00a0f844 = 4;
          _memcpy(&local_8,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          FUN_004ce970(local_8);
          for (local_14 = 0; local_14 < local_8; local_14 = local_14 + 1) {
            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
              DAT_00a117e4 = 1;
              return 0;
            }
            DAT_00a0f844 = 4;
            _Size = 4;
            _Src = (void *)(DAT_00a0f824 + DAT_00a0f820);
            _Dst = (void *)FUN_004ce990(local_14);
            _memcpy(_Dst,_Src,_Size);
            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          }
          uVar1 = 1;
        }
      }
    }
  }
  return uVar1;
}

