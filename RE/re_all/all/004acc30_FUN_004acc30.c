
undefined4 FUN_004acc30(void)

{
  undefined4 uVar1;
  void *pvVar2;
  byte *pbVar3;
  uint *puVar4;
  void *pvVar5;
  uint uVar6;
  size_t sVar7;
  uint local_10;
  uint local_c;
  byte local_6;
  char local_5;
  
  if (DAT_00a0f828 < DAT_00a0f820 + 1) {
    DAT_00a117e4 = 1;
    uVar1 = 0;
  }
  else {
    DAT_00a0f844 = 1;
    _memcpy(&local_5,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (local_5 == '\x01') {
      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
        DAT_00a117e4 = 1;
        return 0;
      }
      DAT_00a0f844 = 4;
      _memcpy(&local_c,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      FUN_004cf7d0(local_c);
      FUN_004ce970(local_c);
      for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
        if (DAT_00a0f828 < DAT_00a0f820 + 1) {
          DAT_00a117e4 = 1;
          return 0;
        }
        DAT_00a0f844 = 1;
        sVar7 = 1;
        pvVar5 = (void *)(DAT_00a0f824 + DAT_00a0f820);
        pvVar2 = (void *)FUN_004cd7c0(local_10);
        _memcpy(pvVar2,pvVar5,sVar7);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        pbVar3 = (byte *)FUN_004cd7c0(local_10);
        if (*pbVar3 < 0xfa) {
          if (DAT_00a0f828 < DAT_00a0f820 + 1) {
            DAT_00a117e4 = 1;
            return 0;
          }
          DAT_00a0f844 = 1;
          _memcpy(&local_6,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          uVar6 = (uint)local_6;
          puVar4 = (uint *)FUN_004ce990(local_10);
          *puVar4 = uVar6;
        }
        else {
          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
            DAT_00a117e4 = 1;
            return 0;
          }
          DAT_00a0f844 = 4;
          sVar7 = 4;
          pvVar2 = (void *)(DAT_00a0f824 + DAT_00a0f820);
          pvVar5 = (void *)FUN_004ce990(local_10);
          _memcpy(pvVar5,pvVar2,sVar7);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}

