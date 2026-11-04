
undefined4
FUN_005492e0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint _Size;
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *_Dst;
  int iVar6;
  undefined1 uStack_2;
  
  uVar1 = FUN_005440f0(param_1,param_2,param_3,param_4,param_5);
  _Size = *(uint *)(param_1 + 0x428);
  iVar6 = *(int *)(param_1 + 0x42c);
  _Dst = *(undefined4 **)(param_1 + 0x434);
  iVar4 = *(int *)(param_1 + 0x430) - *(byte *)(param_1 + 4) * _Size;
  uVar3 = (undefined2)uVar1;
  switch((uint)*(byte *)(param_1 + 4)) {
  case 1:
    if (0 < iVar6) {
      do {
        if (0 < (int)_Size) {
          _memset(_Dst,param_2,_Size);
          _Dst = (undefined4 *)((int)_Dst + _Size);
        }
        _Dst = (undefined4 *)((int)_Dst + iVar4);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      return 0;
    }
    break;
  case 2:
    if (0 < iVar6) {
      param_1 = iVar6;
      do {
        puVar5 = _Dst;
        if (0 < (int)_Size) {
          puVar5 = (undefined4 *)((int)_Dst + _Size * 2);
          for (uVar2 = _Size >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
            *_Dst = CONCAT22(uVar3,uVar3);
            _Dst = _Dst + 1;
          }
          for (uVar2 = (uint)((_Size & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined2 *)_Dst = uVar3;
            _Dst = (undefined4 *)((int)_Dst + 2);
          }
        }
        _Dst = (undefined4 *)((int)puVar5 + iVar4);
        param_1 = param_1 + -1;
      } while (param_1 != 0);
      return 0;
    }
    break;
  case 3:
    if (0 < iVar6) {
      uStack_2 = (undefined1)((uint)uVar1 >> 0x10);
      do {
        if (0 < (int)_Size) {
          uVar2 = _Size;
          do {
            *(undefined2 *)_Dst = uVar3;
            *(undefined1 *)((int)_Dst + 2) = uStack_2;
            _Dst = (undefined4 *)((int)_Dst + 3);
            uVar2 = uVar2 - 1;
          } while (uVar2 != 0);
        }
        _Dst = (undefined4 *)((int)_Dst + iVar4);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      return 0;
    }
    break;
  case 4:
    if (0 < iVar6) {
      param_1 = iVar6;
      do {
        if (0 < (int)_Size) {
          puVar5 = _Dst;
          for (uVar2 = _Size; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = uVar1;
            puVar5 = puVar5 + 1;
          }
          _Dst = _Dst + _Size;
        }
        _Dst = (undefined4 *)((int)_Dst + iVar4);
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return 0;
}

