
undefined4
FUN_00549430(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,
            undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 *_Dst;
  undefined4 *puVar6;
  
  iVar2 = *(int *)(param_1 + 0x428);
  if ((((iVar2 <= param_2) || ((int)param_4 < 1)) ||
      (iVar1 = *(int *)(param_1 + 0x42c), iVar1 <= param_3)) || (param_5 < 1)) {
    return 0xffffffff;
  }
  if (param_2 < 0) {
    param_4 = param_4 + param_2;
    param_2 = 0;
  }
  else if (iVar2 < (int)(param_2 + param_4)) {
    param_4 = iVar2 - param_2;
  }
  if (param_3 < 0) {
    param_5 = param_5 + param_3;
    param_3 = 0;
  }
  else if (iVar1 < param_5 + param_3) {
    param_5 = iVar1 - param_3;
  }
  if (*(char *)(param_1 + 4) == '\x01') {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005440f0(param_1,param_6,param_7,param_8,param_9);
  }
  uVar3 = (uint)*(byte *)(param_1 + 4);
  _Dst = (undefined4 *)
         (*(int *)(param_1 + 0x430) * param_3 + uVar3 * param_2 + *(int *)(param_1 + 0x434));
  iVar2 = *(int *)(param_1 + 0x430) - uVar3 * param_4;
  uVar4 = (undefined2)uVar5;
  switch(uVar3) {
  case 1:
    if (0 < param_5) {
      do {
        if (0 < (int)param_4) {
          _memset(_Dst,param_6,param_4);
          _Dst = (undefined4 *)((int)_Dst + param_4);
        }
        _Dst = (undefined4 *)((int)_Dst + iVar2);
        param_5 = param_5 + -1;
      } while (param_5 != 0);
      return 0;
    }
    break;
  case 2:
    if (0 < param_5) {
      param_2 = param_5;
      do {
        puVar6 = _Dst;
        if (0 < (int)param_4) {
          puVar6 = (undefined4 *)((int)_Dst + param_4 * 2);
          for (uVar3 = param_4 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
            *_Dst = CONCAT22(uVar4,uVar4);
            _Dst = _Dst + 1;
          }
          for (uVar3 = (uint)((param_4 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined2 *)_Dst = uVar4;
            _Dst = (undefined4 *)((int)_Dst + 2);
          }
        }
        _Dst = (undefined4 *)((int)puVar6 + iVar2);
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return 0;
    }
    break;
  case 3:
    if (0 < param_5) {
      param_1._2_1_ = (undefined1)((uint)uVar5 >> 0x10);
      do {
        if (0 < (int)param_4) {
          uVar3 = param_4;
          do {
            *(undefined2 *)_Dst = uVar4;
            *(undefined1 *)((int)_Dst + 2) = param_1._2_1_;
            _Dst = (undefined4 *)((int)_Dst + 3);
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        _Dst = (undefined4 *)((int)_Dst + iVar2);
        param_5 = param_5 + -1;
      } while (param_5 != 0);
      return 0;
    }
    break;
  case 4:
    if (0 < param_5) {
      do {
        if (0 < (int)param_4) {
          puVar6 = _Dst;
          for (uVar3 = param_4; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = uVar5;
            puVar6 = puVar6 + 1;
          }
          _Dst = _Dst + param_4;
        }
        _Dst = (undefined4 *)((int)_Dst + iVar2);
        param_5 = param_5 + -1;
      } while (param_5 != 0);
    }
  }
  return 0;
}

