
void FUN_00514f20(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  *in_EAX = 0;
  in_EAX[1] = 0xffffffff;
  in_EAX[0x222] = 0;
  in_EAX[0x223] = 0;
  in_EAX[0x10f] = 0;
  in_EAX[0x21f] = 0;
  if (*(int *)(unaff_EDI + 0x134) == 0) {
    if (*(int *)(unaff_EDI + 0x138) == 0) {
      if (*(int *)(unaff_EDI + 0x148) == 0) {
        if (*(int *)(unaff_EDI + 0x158) == 0) goto LAB_005150d0;
        in_EAX[0x222] = *(int *)(unaff_EDI + 0x158);
        in_EAX[0x223] = *(undefined4 *)(unaff_EDI + 0x15c);
      }
      else {
        puVar1 = in_EAX + 2;
        iVar2 = FUN_00544b50(*(int *)(unaff_EDI + 0x148),*(undefined4 *)(unaff_EDI + 0x14c),puVar1,1
                            );
        if (iVar2 == -1) {
          return;
        }
        if ((*(int *)(unaff_EDI + 0x150) == 0) || (*(int *)(unaff_EDI + 0x154) == 0)) {
          FUN_0056d380(in_EAX + 0x112,0,0x440);
          in_EAX[0x222] = puVar1;
          *in_EAX = 1;
        }
        else {
          iVar3 = FUN_00544b50(*(int *)(unaff_EDI + 0x150),*(int *)(unaff_EDI + 0x154),
                               in_EAX + 0x112,1);
          if (iVar3 == -1) {
            if (iVar2 == 1) {
              FUN_005421c0(puVar1);
              return;
            }
            return;
          }
          in_EAX[0x223] = in_EAX + 0x112;
          in_EAX[0x222] = puVar1;
          *in_EAX = 1;
        }
      }
      in_EAX[1] = 1;
    }
    else {
      iVar2 = FUN_0054f230();
      in_EAX[1] = iVar2;
      in_EAX[0x222] = in_EAX + 2;
      if (iVar2 == 0) {
        in_EAX[0x223] = in_EAX + 0x112;
      }
      *in_EAX = 1;
    }
  }
  else {
    iVar2 = FUN_0054f230();
    in_EAX[1] = iVar2;
    in_EAX[0x222] = in_EAX + 2;
    if (iVar2 == 0) {
      in_EAX[0x223] = in_EAX + 0x112;
    }
    *in_EAX = 1;
  }
LAB_005150d0:
  if ((-1 < (int)in_EAX[1]) && (*(int *)(unaff_EDI + 0x188) == 1)) {
    FUN_00541150(in_EAX[0x222]);
    if (in_EAX[0x223] != 0) {
      FUN_00541150(in_EAX[0x223]);
    }
  }
  return;
}

