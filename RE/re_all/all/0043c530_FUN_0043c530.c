
undefined4 __fastcall FUN_0043c530(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbVar3;
  int iVar4;
  undefined4 uVar5;
  size_t sVar6;
  undefined4 uVar7;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_8c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_70 [28];
  void *local_54;
  size_t local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  void *local_3c;
  size_t local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  byte local_d;
  int local_c;
  int local_8;
  
  local_1c = FUN_004174a0(1,0,param_1);
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_1c,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_18 = FUN_004cd340();
  local_14 = 0;
  local_d = 0;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_18,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_20 = 0; local_20 < local_18; local_20 = local_20 + 1) {
    FUN_004cde80(local_20);
    local_14 = FUN_004cd340();
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_14,4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    for (local_24 = 0; local_24 < local_14; local_24 = local_24 + 1) {
      iVar1 = local_24;
      FUN_004cde80(local_20);
      FUN_004cde80(iVar1);
      local_d = FUN_004ce080();
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 1;
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_d,1);
      }
      else {
        DAT_00a0f844 = 1;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      local_28 = 0;
      while( true ) {
        iVar1 = local_24;
        FUN_004cde80(local_20);
        FUN_004cde80(iVar1);
        iVar1 = FUN_004ce080();
        if (iVar1 <= local_28) break;
        if (DAT_00a117e8 == 0) {
          DAT_00a0f844 = 4;
          sVar6 = 4;
          iVar1 = local_24;
          iVar4 = local_28;
          FUN_004cde80(local_20);
          FUN_004cde80(iVar1);
          pvVar2 = (void *)FUN_004ce990(iVar4);
          _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,sVar6);
        }
        else {
          DAT_00a0f844 = 4;
        }
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        local_28 = local_28 + 1;
      }
    }
  }
  local_8 = FUN_004cd340();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_8,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_2c = 0; local_2c < local_8; local_2c = local_2c + 1) {
    FUN_004cde80(local_2c);
    local_c = FUN_004ce080();
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_c,4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    for (local_30 = 0; local_30 < local_c; local_30 = local_30 + 1) {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        sVar6 = 4;
        iVar1 = local_30;
        FUN_004cde80(local_2c);
        pvVar2 = (void *)FUN_004ce990(iVar1);
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,sVar6);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  local_8 = FUN_004cc430();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_8,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_34 = 0; local_34 < local_8; local_34 = local_34 + 1) {
    FUN_004cc4c0(local_34);
    iVar1 = FUN_004e5650();
    if (32000 < iVar1) {
      uVar7 = 32000;
      uVar5 = 0;
      pbVar3 = local_70;
      FUN_004cc4c0(local_34);
      FUN_004cbc20(pbVar3,uVar5,uVar7);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_70);
    }
    FUN_004cc4c0(local_34);
    iVar1 = FUN_004e5650();
    local_38 = iVar1 + 1;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_38,4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    FUN_004cc4c0(local_34);
    local_3c = (void *)FUN_004cbb30();
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = local_38;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_3c,local_38);
    }
    else {
      DAT_00a0f844 = local_38;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  local_18 = FUN_004cd340();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_18,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_40 = 0; local_40 < local_18; local_40 = local_40 + 1) {
    FUN_004cde80(local_40);
    local_d = FUN_004ce080();
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_d,1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    for (local_44 = 0; local_44 < (int)(uint)local_d; local_44 = local_44 + 1) {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        sVar6 = 4;
        iVar1 = local_44;
        FUN_004cde80(local_40);
        pvVar2 = (void *)FUN_004ce990(iVar1);
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,sVar6);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  local_18 = FUN_004cd340();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_18,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_48 = 0; local_48 < local_18; local_48 = local_48 + 1) {
    FUN_004cde80(local_48);
    local_d = FUN_004cc430();
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_d,1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    for (local_4c = 0; local_4c < (int)(uint)local_d; local_4c = local_4c + 1) {
      iVar1 = local_4c;
      FUN_004cde80(local_48);
      FUN_004cc4c0(iVar1);
      iVar1 = FUN_004e5650();
      if (32000 < iVar1) {
        uVar7 = 32000;
        uVar5 = 0;
        pbVar3 = local_8c;
        iVar1 = local_4c;
        FUN_004cde80(local_48);
        FUN_004cc4c0(iVar1);
        FUN_004cbc20(pbVar3,uVar5,uVar7);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_8c);
      }
      iVar1 = local_4c;
      FUN_004cde80(local_48);
      FUN_004cc4c0(iVar1);
      iVar1 = FUN_004e5650();
      local_50 = iVar1 + 1;
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_50,4);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      iVar1 = local_4c;
      FUN_004cde80(local_48);
      FUN_004cc4c0(iVar1);
      local_54 = (void *)FUN_004cbb30();
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = local_50;
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_54,local_50);
      }
      else {
        DAT_00a0f844 = local_50;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  return 1;
}

