
/* WARNING: Removing unreachable block (ram,0x0056e64d) */
/* WARNING: Removing unreachable block (ram,0x0056e655) */
/* WARNING: Removing unreachable block (ram,0x0056e657) */

void FUN_0056e590(uint param_1,uint param_2,undefined4 param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *in_EAX;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  param_4 = __allrem(param_3,param_4,0xc,0);
  if (0 < (int)param_2) {
    if (param_4 != 0) {
      do {
        *(byte *)in_EAX = (byte)*in_EAX ^ *(byte *)(param_4 + (int)param_5);
        param_4 = param_4 + 1;
        in_EAX = (uint *)((int)in_EAX + 1);
        bVar7 = param_1 != 0;
        param_1 = param_1 - 1;
        param_2 = param_2 + -1 + (uint)bVar7;
      } while ((int)param_4 < 0xc);
    }
    iVar6 = 0;
    if (-1 < (int)param_2) {
      if ((0 < (int)param_2) || (0xb < param_1)) {
        iVar5 = __alldiv(param_1,param_2,0xc,0);
        bVar7 = param_1 < (uint)(iVar5 * 0xc);
        param_1 = param_1 + iVar5 * -0xc;
        uVar1 = *param_5;
        uVar2 = param_5[1];
        uVar3 = param_5[2];
        param_2 = param_2 - bVar7;
        do {
          in_EAX[1] = in_EAX[1] ^ uVar2;
          *in_EAX = *in_EAX ^ uVar1;
          in_EAX[2] = in_EAX[2] ^ uVar3;
          in_EAX = in_EAX + 3;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      if (-1 < (int)param_2) {
        if (0 < (int)param_2) goto LAB_0056e6e3;
        do {
          if (param_1 == 0) {
            return;
          }
LAB_0056e6e3:
          do {
            *(byte *)in_EAX = (byte)*in_EAX ^ *(byte *)(iVar6 + (int)param_5);
            iVar6 = iVar6 + 1;
            in_EAX = (uint *)((int)in_EAX + 1);
            if (iVar6 == 0xc) {
              iVar6 = 0;
            }
            bVar7 = param_1 != 0;
            param_1 = param_1 - 1;
            param_2 = param_2 + -1 + (uint)bVar7;
          } while (0 < (int)param_2);
        } while (-1 < (int)param_2);
      }
    }
    return;
  }
  param_2 = param_1;
  if (0xb < param_1) {
    if (param_4 != 0) {
      do {
        *(byte *)in_EAX = (byte)*in_EAX ^ *(byte *)((int)param_5 + param_4);
        param_4 = param_4 + 1;
        in_EAX = (uint *)((int)in_EAX + 1);
        param_1 = param_1 - 1;
      } while (param_4 < 0xc);
      param_4 = 0;
      param_2 = param_1;
      if (param_1 < 0xc) goto LAB_0056e62a;
    }
    uVar4 = param_2 / 0xc;
    param_2 = param_2 % 0xc;
    uVar1 = *param_5;
    uVar2 = param_5[1];
    uVar3 = param_5[2];
    do {
      *in_EAX = *in_EAX ^ uVar1;
      in_EAX[1] = in_EAX[1] ^ uVar2;
      in_EAX[2] = in_EAX[2] ^ uVar3;
      in_EAX = in_EAX + 3;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
LAB_0056e62a:
  if (param_2 != 0) {
    do {
      *(byte *)in_EAX = (byte)*in_EAX ^ *(byte *)((int)param_5 + param_4);
      param_4 = param_4 + 1;
      if (param_4 == 0xc) {
        param_4 = 0;
      }
      in_EAX = (uint *)((int)in_EAX + 1);
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}

