#ifndef SUPPRESSOR_H
#define SUPPRESSOR_H

namespace NSApplication {

namespace NSSupport {

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

} // namespace NSSupport

} // namespace NSApplication

#endif // SUPPRESSOR_H
