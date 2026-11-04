
longlong FUN_004f9100(int param_1,undefined4 param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  void *_Memory;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  longlong lVar10;
  int iVar11;
  int local_2c;
  uint local_24;
  uint local_1c;
  uint local_18;
  
  local_24 = 0xffff;
  lVar3 = 0;
  iVar4 = FUN_00401750(param_1,param_2,0,0,2);
  if (iVar4 == 0) {
    lVar10 = FUN_004017d0(param_1,param_2);
    uVar8 = (uint)((ulonglong)lVar10 >> 0x20);
    uVar5 = (uint)lVar10;
    if ((uVar8 == 0) && (uVar5 < 0xffff)) {
      local_24 = uVar5;
    }
    _Memory = _malloc(0x404);
    if (_Memory == (void *)0x0) {
      lVar3 = 0;
    }
    else {
      local_1c = 4;
      local_18 = 0;
      while ((local_18 == 0 && (local_1c < local_24))) {
        if ((local_1c < 0xfffffc00) && (local_1c + 0x400 <= local_24)) {
          bVar9 = 0xfffffbff < local_1c;
          local_1c = local_1c + 0x400;
          local_18 = (uint)bVar9;
        }
        else {
          local_1c = local_24;
          local_18 = 0;
        }
        lVar2 = lVar10 - CONCAT44(local_18,local_1c);
        uVar6 = (uint)lVar2;
        uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
        uVar1 = uVar8 - uVar7;
        iVar4 = uVar1 - (uVar5 < uVar6);
        if (((uVar8 < uVar7 || uVar1 < (uVar5 < uVar6)) || iVar4 == 0) && (uVar5 - uVar6 < 0x405)) {
          iVar11 = uVar5 - uVar6;
        }
        else {
          iVar11 = 0x404;
        }
        iVar4 = FUN_00401750(param_1,param_2,lVar2,0,iVar11,uVar5 - uVar6,iVar4);
        if ((iVar4 != 0) ||
           (iVar4 = (**(code **)(param_1 + 4))
                              (*(undefined4 *)(param_1 + 0x1c),param_2,_Memory,iVar11),
           iVar4 != iVar11)) break;
        iVar4 = iVar11 + -3;
        do {
          local_2c = iVar4;
          iVar4 = local_2c + -1;
          if (local_2c < 1) goto LAB_004f9307;
        } while ((((*(char *)((int)_Memory + iVar4) != 'P') ||
                  (*(char *)((int)_Memory + local_2c) != 'K')) ||
                 (*(char *)((int)_Memory + local_2c + 1) != '\x05')) ||
                (*(char *)((int)_Memory + local_2c + 2) != '\x06'));
        lVar3 = lVar2 + iVar4;
LAB_004f9307:
        if (lVar3 != 0) break;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
      }
    }
  }
  else {
    lVar3 = 0;
  }
  return lVar3;
}

