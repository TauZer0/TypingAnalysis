#ifndef SUPPRESSOR_H
#define SUPPRESSOR_H

namespace NSApplication::NSSupport {

class Suppressor {
public:
  void activate();
  void deactivate();
  bool isActive() const;

  // BasicLockable
  void lock();
  void unlock();

private:
  bool IsActive_{false};
};

} // namespace NSApplication::NSSupport

#endif // SUPPRESSOR_H
